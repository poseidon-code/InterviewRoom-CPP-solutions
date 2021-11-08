// PROBLEM: kth smallest node in BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/


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

int result;
int value;

void traverse (Node *root) {
    if (!root || !root->data) return;
    traverse(root->left);
    value--;
    if (value==0) result = root->data;
    traverse(root->right);
}

// SOLUTION
int kth_smallest (Node *root, int k) {
    value = k;
    traverse(root);
    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {3,1,4,NULL,2};
    int k = 1;
    Node *root = NBST(elements, root, 0, elements.size());

    // OUTPUT :
    cout<<kth_smallest(root, k)<<endl;
    
    return 0;
}