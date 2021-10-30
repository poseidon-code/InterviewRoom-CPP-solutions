// PROBLEM: All Root to Leaf path sum
// https://leetcode.com/problems/path-sum-ii/
// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/


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
void traverse (Node *root, int target, vector<int> &path, vector<vector<int>> &paths) {
    if (!root) return;
    path.push_back(root->data);
    
    if (!root->left && !root->right && target==root->data)
        paths.push_back(path);

    traverse(root->left, target - root->data, path, paths);
    traverse(root->right, target - root->data, path, paths);
    path.pop_back();
}

vector<vector<int>> all_path_sum (Node *root, int target) {
    vector<vector<int> > paths;
    vector<int> path;
    
    traverse(root, target, path, paths);
    return paths; 
}


int main() {
    // INPUT :
    vector<int> elements = {1,2,2};
    int target = 3;
    Node *root = NBT(elements, root, 0, elements.size());

    // OUTPUT :
    auto result = all_path_sum(root, target);
    cout<<"["; 
    for (auto x : result) {
        cout<<"[";
        for (auto y : x) {
            if (y==0) continue;
            cout<<y<<",";
        }
        cout<<"\b],";
    }
    cout<<"\b]"<<endl;

    return 0;
}