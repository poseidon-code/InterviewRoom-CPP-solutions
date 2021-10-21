// PROBLEM: Check if a binary tree is BST
// https://practice.geeksforgeeks.org/problems/check-for-bst/1


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
bool traverse (Node *root, Node *min, Node *max) {
    if (root==NULL) return true;
    if (min && root->data<=min->data) return false;
    if (max && root->data>=max->data) return false;

    bool l = traverse(root->left, min, root);
    bool r = traverse(root->right, root, max);

    return l && r;
}

bool is_bst (Node *root) {
    return traverse(root, NULL, NULL);
}


int main() {
    // INPUT :
    vector<int> elements = {2,1,3};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    is_bst(root) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}