// PROBLEM: Maximum path sum between two leaf nodes
// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-between-two-leaves_794950

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
int traverse (Node *root, int result) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;

    int ls = traverse(root->left, result);
    int rs = traverse(root->right, result);

    if (root->left && root->right) {
        result = max(result, ls+rs+root->data);
        return max(ls, rs) + root->data;
    }

    return (!root->left) ? rs+root->data : ls+root->data;
}

int leaf_path_sum (Node *root) {
    int result = INT32_MIN;
    int v = traverse(root, result);
    
    if (result==INT32_MIN) return v;
    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    cout<<leaf_path_sum(root)<<endl;

    return 0;
}