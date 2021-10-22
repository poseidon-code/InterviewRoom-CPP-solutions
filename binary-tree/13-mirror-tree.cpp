// PROBLEM: Convert binary tree to its mirror tree
// https://practice.geeksforgeeks.org/problems/mirror-tree/1


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
void mirror (Node *root) {
    if (root==NULL) return;
    else {
        Node *t;
        mirror(root->left);
        mirror(root->right);
        t = root->left;
        root->left = root->right;
        root->right = t;
    }
}


int main() {
    // INPUT :
    vector<int> elements = {1,3,2,NULL,NULL,5,4};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    mirror(root);

    return 0;
}