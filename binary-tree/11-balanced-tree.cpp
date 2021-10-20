// PROBLEM: Check if binary tree is balanced
// https://leetcode.com/problems/balanced-binary-tree/


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
int traverse (Node *root) {
    if (root==NULL) return 0;
    return max(traverse(root->left), traverse(root->right))+1;
}

bool is_balanced (Node *root) {
    if (root==NULL) return true;

    int l = traverse(root->left);
    int r = traverse(root->right);

    return abs(l-r) <= 1 && is_balanced(root->left) && is_balanced(root->right);
}


int main() {
    // INPUT :
    vector<int> elements = {9,3,20,NULL,NULL,15,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    is_balanced(root) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}
