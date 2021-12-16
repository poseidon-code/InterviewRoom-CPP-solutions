// PROBLEM: Interleaving String
// https://leetcode.com/problems/interleaving-string/
// https://www.interviewbit.com/problems/interleaving-strings/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// SOLUTION
bool is_interleaving (string s1, string s2, string s3) {
    int m = s1.length(), n = s2.length();
    if(s3.length() != m + n) return false;

    bool dp[m+1][n+1];
    
    for(int i=0; i<m+1; i++) {
        for(int j=0; j< n+1; j++){
            if(i==0 && j==0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
    }

    return dp[m][n];
}


int main() {
    // INPUT :
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    // OUTPUT :
    is_interleaving(s1, s2, s3) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}