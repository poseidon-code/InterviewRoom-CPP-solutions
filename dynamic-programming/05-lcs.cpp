// PROBLEM: Longest common subsequence (delete operation for two strings)
// https://leetcode.com/problems/delete-operation-for-two-strings/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// SOLUTION
int lcs (string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i=m; i>=0; i--) {
        for (int j=n; j>=0; j--) {
            if (i<m || j<n) {
                dp[i][j] = 
                    i<m && j<n && word1[i]==word2[j]
                    ? dp[i+1][j+1]
                    : 1 + min(
                            (i<m ? dp[i+1][j] : INT16_MAX), 
                            (j<n ? dp[i][j+1] : INT16_MAX)
                        );
            }
        }
    }

    return dp[0][0];
}


int main() {
    // INPUT :
    string word1 = "sea";
    string word2 = "eat";

    // OUTPUT :
    cout<<lcs(word1, word2)<<endl;

    return 0;
}