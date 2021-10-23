// PROBLEM: Check if 2 binary trees are mirror of each other
// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// SOLUTION
bool check_mirror (int n, int e, int A[], int B[]) {
    map<int, vector<int>> mp1, mp2;

    for (int i=0; i<2*e; i+=2)
        mp1[A[i]].push_back(A[i+1]);
    
    for (int i=0; i<2*e; i+=2)
        mp2[B[i]].push_back(B[i+1]);

    for (auto it : mp1) {
        vector<int> v = it.second;
        reverse(v.begin(), v.end());
        mp1[it.first] = v;
    }

    return mp1 == mp2;
}


int main() {
    // INPUT :
    int n = 3;
    int e = 2;
    int A[] = {1,2,1,3};
    int B[] = {1,3,1,2};

    // OUTPUT :
    check_mirror(n, e, A, B) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}