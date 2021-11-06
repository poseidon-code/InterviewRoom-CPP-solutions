// PROBLEM: Lowest common ancestor in BST
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


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

Node *NBST (vector<int> elements, Node *root, int i, int n) {
    if (n==0) return NULL;
    
    if (i<n) {
        Node *temp = new Node(elements[i]);
        root = temp;
        root->left = NBST(elements, root->left, 2*i+1, n);
        root->right = NBST(elements, root->right, 2*i+2, n);
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
    vector<int> elements = {6,2,8,0,4,7,9,NULL,NULL,3,5,NULL,NULL,NULL,NULL};
    Node *root = NBST(elements, root, 0, elements.size());
    auto p = root->left;
    auto q = root->left->right;

    // OUTPUT :
    cout<<lca(root, p, q)->data<<endl;
    return 0;
}