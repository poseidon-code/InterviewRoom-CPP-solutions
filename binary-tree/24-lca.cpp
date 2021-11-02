// PROBLEM: Least Common Ancestor of two nodes
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


#include<iostream>
#include<vector>

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
Node* lca (Node *root, Node *p, Node *q) {
    if (!root || root==p || root==q) return root;
    
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    
    return !left ? right : !right ? left : root;
}


int main() {
    // INPUT :
    vector<int> elements = {3,5,1,6,2,0,8,NULL,NULL,7,4};
    Node *root = NBT(elements, root, 0, elements.size());
    auto p = root->left;
    auto q = root->right;

    // OUTPUT :
    cout<<lca(root, p, q)->data<<endl;

    return 0;
}