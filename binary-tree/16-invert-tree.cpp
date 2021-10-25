// PROBLEM: Invert a binary tree
// https://leetcode.com/problems/invert-binary-tree/
// https://www.interviewbit.com/problems/invert-the-binary-tree/


#include<iostream>
#include<vector>
#include<stack>

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
Node *invert (Node *root) {
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node *p = s.top();
        s.pop();
        if (p) {
            s.push(p->left);
            s.push(p->right);
            swap(p->left, p->right);
        }
    }

    return root;
}


int main() {
    // INPUT :
    vector<int> elements = {4,2,7,1,3,6,9};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    invert(root);

    return 0;
}