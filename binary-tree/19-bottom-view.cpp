// PROBLEM: Bottom view of binary tree
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


#include<iostream>
#include<vector>
#include<queue>
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
vector<int> bottom_view (Node *root) {
    vector<int> result;
    if (!root) return result;
    
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while (!q.empty()) {
        Node *x = q.front().first;
        int p = q.front().second;
        q.pop();
        
        m[p] = x->data;
        if (x->left) q.push({x->left, p-1});
        if (x->right) q.push({x->right, p+1});
    }

    for (auto x : m) result.push_back(x.second);
    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = bottom_view(root);
    cout<<"["; for (auto x : result)
        {if (x==0) continue; cout<<x<<" ";}
    cout<<"\b]"<<endl;

    return 0;
}