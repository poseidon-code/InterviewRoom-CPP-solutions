// PROBLEM: Symmetric tree
// https://leetcode.com/problems/symmetric-tree/
// https://www.interviewbit.com/problems/symmetric-binary-tree/


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
bool traverse (Node *p, Node *q) {
    if (!p && !q) return true;
    else if (!p || !q) return false;
    
    if (p->data != q->data) return false;
    
    return traverse(p->left,q->right) && traverse(p->right, q->left); 
}

bool is_symmetric (Node *root) {
    if (root == NULL) return true;
    return traverse(root->left, root->right);
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,2,3,4,4,3};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    is_symmetric(root) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}