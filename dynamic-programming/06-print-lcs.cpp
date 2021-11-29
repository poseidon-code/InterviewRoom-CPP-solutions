// PROBLEM: Print longest common subsequence
// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// SOLUTION
vector<int> lcs (vector<int> &A, vector<int> &B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> lca(n+1, vector<int>(m+1, 0));

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (A[i-1]==B[j-1])
                lca[i][j] = lca[i-1][j-1]+1;
            else
                lca[i][j] = max(lca[i][j-1], lca[i-1][j]);
    
    int i=n, j=m;
    vector<int> C;
    while (i>0 && j>0) {
        if (A[i-1]==B[j-1]) {
            C.push_back(A[i-1]);
            i--; j--;
        }
        else
            if (lca[i-1][j]>lca[i][j-1]) i--;
            else j--;
    }

    reverse(C.begin(), C.end());
    return C;
}


int main() {
    // INPUT :
    vector<int> A = {1,2,3,4,1};
    vector<int> B = {3,4,1,2,1,3};

    // OUTPUT :
    auto result = lcs(A,B);
    cout<<"["; for (auto x : result) cout<<x<<" "; cout<<"\b]"<<endl;

    return 0;
}