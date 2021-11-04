// PROBLEM: Insert Node into binary search tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/


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
Node* insert (Node *root, int value) {
    Node **c = &root;
    while (*c)
        c = value > (*c)->data ? &(*c)->right : &(*c)->left;
    *c = new Node(value);
    return root;
}


int main() {
    // INPUT :
    vector<int> elements = {4,2,7,1,3};
    int value = 5;
    Node *root = NBST(elements, root, 0, elements.size());

    // OUTPUT :
    insert(root, value);

    return 0;
}