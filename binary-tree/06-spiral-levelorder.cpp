// PROBLEM: Level order traversal in sipral form
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/


#include<iostream>
#include<vector>
#include<queue>

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
vector<vector<int>> levelorder_spiral (Node *root) {
    queue<Node*> q;
    vector<vector<int>> result;
    bool l2r = true;
    
    if (root==NULL) return result;

    q.push(root);

    while (!q.empty()) {
        int s = q.size();
        vector<int> row(s);

        for (int i=0; i<s; i++) {
            Node *t = q.front();
            q.pop();

            int index = l2r ? i : s-1-i;

            row[index] = t->data;
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }

        l2r = !l2r;
        result.push_back(row);
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {3,9,20,NULL,NULL,15,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = levelorder_spiral(root);
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