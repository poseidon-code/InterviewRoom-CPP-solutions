// PROBLEM: Path sum
// https://www.interviewbit.com/problems/path-sum/
// https://leetcode.com/problems/path-sum/


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
bool has_path_sum (Node *root, int target) {
    if (!root) return false;

    if (root->left == root->right) return target == root->data;

    return has_path_sum(root->left, target - root->data) || has_path_sum(root->right, target - root->data);
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3};
    int target = 3;
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    has_path_sum(root, target) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}