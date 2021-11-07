// PROBLEM: Inorder successor in BST
// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

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

void traverse (Node *root, Node* &p, Node* &s, int key) {
    if(root==NULL) return;

    traverse(root->left, p, s, key);
    if(root->data == key)
        p=root;
    else if(p!=NULL && s==NULL) {
        s=root;
        return;
    }
    traverse(root->right, p, s, key);
}

// SOLUTION
Node* inorder_successor (Node *root, Node *x) {
    if(root==NULL) return root;
            
    Node *p=NULL;
    Node *s=NULL;
    traverse(root, p, s, x->data);
    return s;
}


int main() {
    // INPUT :
    vector<int> elements = {2,1,3};
    Node *root = NBST(elements, root, 0, elements.size());
    Node *x = root->left;

    // OUTPUT :
    cout<<inorder_successor(root, x)->data<<endl;
    return 0;
}