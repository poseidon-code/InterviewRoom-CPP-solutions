// PROBLEM: Maximum path sum from any node to node
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


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
int max_sum = INT32_MIN;

int traverse (Node *root) {
    if (!root) return 0;
    int ls = max(traverse(root->left),0);
    int rs = max(traverse(root->right),0);
    max_sum = max(max_sum, ls+rs+root->data);
    return max(ls, rs) + root->data;
}

int node_path_sum (Node *root) {
    int v = traverse(root);
    
    if (max_sum==INT32_MIN) return v;
    return max_sum;
}


int main() {
    // INPUT :
    vector<int> elements = {-10,9,20,NULL,NULL,15,7};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    cout<<node_path_sum(root)<<endl;

    return 0;
}