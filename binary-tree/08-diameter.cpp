// PROBLEM: Diameter of binary tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
int traverse (Node *root, int &d) {
    if (root==NULL) return 0;
    int ld = traverse(root->left, d);
    int rd = traverse(root->right, d);
    d = max(d, ld+rd);
    return max(ld, rd)+1;
}

int diameter (Node *root) {
    int d = 0;
    traverse(root, d);
    return d;
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3,4,5};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    cout<<diameter(root)<<endl;

    return 0;
}
