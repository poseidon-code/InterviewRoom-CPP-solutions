// PROBLEM: Populating next right pointers
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include<iostream>
#include<vector>

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node() : data(0), left(NULL), right(NULL), next(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL), next(NULL) {}
    Node(int x, Node *left, Node *right, Node *next) : data(x), left(left), right(right), next(next) {}
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
void connect (Node *root) {
    while (root!=NULL && root->left!=NULL) {
        Node *c = root;
        while (c) {
            c->left->next = c->right;
            c->right->next = c->next ? c->next->left : NULL;
            c = c->next;
        }
        root = root->left;
    }
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3,4,5,6,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    connect(root);

    return 0;
}
