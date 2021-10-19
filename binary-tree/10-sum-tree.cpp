// PROBLEM: Check if sum tree
// https://practice.geeksforgeeks.org/problems/sum-tree/1


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
int traverse (Node *root, bool &result) {
    if (root==NULL) return 0;
    if (!root->left && !root->right) return root->data;

    int ld = traverse(root->left, result);
    int rd = traverse(root->right, result);
    
    if (ld+rd!=root->data) result = false;
    
    return root->data+ld+rd;
}

bool is_sum_tree (Node *root) {
    bool result = true;
    traverse(root, result);
    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {10,20,30,10,10};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    is_sum_tree(root) ? cout<<"True" : cout<<"False";
    cout<<endl;

    return 0;
}
