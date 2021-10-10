// PROBLEM: Inorder traversal
// https://www.interviewbit.com/problems/inorder-traversal/

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
vector<int> inorder (Node *root) {
    stack<Node*> s;
    vector<int> result;
    
    if (root==NULL) return result;

    Node *c = root->left;
    s.push(root);

    while (!s.empty() || c) {
        while (c) {
            s.push(c);
            c=c->left;
        }

        Node *temp = s.top();
        s.pop();
        result.push_back(temp->data);
        c = temp->right;
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> elements = {1,6,2,NULL,NULL,3,NULL};
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = inorder(root);
    cout<<"["; for (auto x : result)
        {if (x==0) continue; cout<<x<<" ";}
    cout<<"\b]"<<endl;

    return 0;
}