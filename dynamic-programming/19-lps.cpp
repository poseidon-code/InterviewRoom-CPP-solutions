// PROBLEM: Longest palindromic subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

// SOLUTION
int lps (string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n));
    for (int i=0; i<n; i++) dp[1][i]=1;

    for (int i=2; i<=n; i++) {
        for (int j=0; j<n-i+1; j++) {
            dp[i][j] = s[j]==s[i+j-1] ? 2+dp[i-2][j+1] : max(dp[i-1][j], dp[i-1][j+1]);
        }
    }

    return dp[n][0];
}


int main() {
    // INPUT :
    string s = "bbbab";

    // OUTPUT :
    cout<<lps(s)<<endl;

    return 0;
}