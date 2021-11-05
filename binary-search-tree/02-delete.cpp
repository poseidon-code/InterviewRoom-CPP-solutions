// PROBLEM: Delete node from BST
// https://leetcode.com/problems/delete-node-in-a-bst/


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
Node* delete_node (Node *root, int key) {
    if (root==NULL) return NULL;

    if (root->data == key) {
        if (!root->right) {
            Node* left = root->left;
            delete root;
            return left;
        } else {
            Node* right = root->right;
            while (right->left)
                right = right->left;
            swap(root->data, right->data);
        }
    }

    root->left = delete_node(root->left, key);
    root->right = delete_node(root->right, key);

    return root;
}


int main() {
    // INPUT :
    vector<int> elements = {5,3,6,2,4,NULL,7};
    int key = 3;
    Node *root = NBST(elements, root, 0, elements.size());

    // OUTPUT :
    delete_node(root, key);

    return 0;
}