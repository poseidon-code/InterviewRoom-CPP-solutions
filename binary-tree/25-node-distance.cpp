// PROBLEM: Minimum distance between two nodes
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1


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


Node* lca (Node *root, Node *p, Node *q) {
    if (!root || root==p || root==q) return root;
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    return !left ? right : !right ? left : root;
}

int traverse (Node *root, Node *a) {
    if (!root) return 0;
    if (root->data==a->data) return 1;
    int c = traverse(root->left, a);
    int d = traverse(root->right,a);
    if (!c && !d) return 0;
    else return c+d+1;
}

// SOLUTION
int distance (Node *root, Node *p, Node *q) {
    Node *n = lca(root, p, q);

    int c = traverse(n, p);
    int d = traverse(n, q);

    return c+d-2;
}


int main() {
    // INPUT :
    vector<int> elements = {3,5,1,6,2,0,8,NULL,NULL,7,4};
    Node *root = NBT(elements, root, 0, elements.size());
    auto p = root->left;
    auto q = root->right;

    // OUTPUT :
    cout<<distance(root, p, q)<<endl;

    return 0;
}