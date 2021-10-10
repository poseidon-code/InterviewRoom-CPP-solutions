// PROBLEM: Maximum height of binary tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// https://www.interviewbit.com/problems/max-depth-of-binary-tree/


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
int maximum_height (Node *root) {
    return root == NULL ? 0 : max(maximum_height(root->left), maximum_height(root->right) + 1);
}


int main() {
    // INPUT :
    vector<int> elements = {3,9,20,NULL,NULL,15,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    cout<<maximum_height(root)<<endl;

    return 0;
}