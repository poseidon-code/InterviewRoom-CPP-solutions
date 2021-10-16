// PROBLEM: Right view of binary tree
// https://leetcode.com/problems/binary-tree-right-side-view/

#include<iostream>
#include<vector>
#include<queue>

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
vector<int> right_view (Node *root) {
    queue<Node*> q;
    vector<int> result;
    
    if (root==NULL) return result;
    q.push(root);

    while (!q.empty()) {
        result.push_back(q.back()->data);

        for (int i=q.size(); i>0; i--) {
            Node *t = q.front();
            q.pop();
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,3,NULL,5,NULL,4};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = right_view(root);
    cout<<"["; for (auto x : result)
        {if (x==0) continue; cout<<x<<" ";}
    cout<<"\b]"<<endl;

    return 0;
}
