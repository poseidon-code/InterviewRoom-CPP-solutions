// PROBLEM: Vertical order traversal
// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

Node *NBT (vector<int> elements, Node *root, int i, int n) {
    if (n==0) return NULL;
    
    if (i<n) {
        Node *temp = new Node(elements[i]);
        root = temp;
        root->left = NBT(elements, root->left, 2*i+1, n);
        root->right = NBT(elements, root->right, 2*i+2, n);
    }

    return root;
}



// SOLUTION
map<int, map<int, vector<int>>> m;
void traverse (Node *root, int x, int y) {
    if (root) {
        m[x][y].push_back(root->data);
        traverse(root->left, x-1, y+1);
        traverse(root->right, x+1, y+1);
    }
}

vector<vector<int>> vertical (Node *root) {
    traverse(root, 0, 0);
    vector<vector<int>> result;

    for (auto p : m) {
        vector<int> t;
        for (auto q : p.second) {
            sort(q.second.begin(), q.second.end());
            t.insert(t.end(), q.second.begin(), q.second.end());
        }
        result.push_back(t);
    }
    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3,4,5,6,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = vertical(root);
    cout<<"["; 
    for (auto x : result) {
        cout<<"[";
        for (auto y : x) {
            if (y==0) continue;
            cout<<y<<",";
        }
        cout<<"\b],";

    }
    cout<<"\b]"<<endl;

    return 0;
}