// PROBLEM: Min cost path
// https://www.interviewbit.com/problems/min-sum-path-in-matrix/ 

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int path (vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    int dp[m][n];

    for(int i=m-1; i>=0; i--)
        for(int j=n-1; j>=0; j--)
            if(i==m-1 && j==n-1) dp[i][j] = A[i][j];
            else if(i==m-1) dp[i][j] = A[i][j] + dp[i][j+1];
            else if(j==n-1) dp[i][j] = A[i][j] + dp[i+1][j];            
            else dp[i][j] = A[i][j] + min(dp[i+1][j], dp[i][j+1]);
    
    return dp[0][0];
}


int main() {
    // INPUT :
    vector<vector<int>> A = {{1,3,2},{4,3,1},{5,6,1}};

    // OUTPUT :
    cout<<path(A)<<endl;

    return 0;
}