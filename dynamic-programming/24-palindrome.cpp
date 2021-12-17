// PROBLEM: Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning-ii/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// SOLUTION
int min_cut (string s) {
    int n = s.length();
    vector<int> cut(n+1, 0);
    for (int i=0; i<=n; i++) cut[i] = i-1;
    
    for (int i=0; i<n; i++) {
        for (int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; j++)
            cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j]);

        for (int j=1; i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j]; j++)
            cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j+1]);
    }

    return cut[n];
}


int main() {
    // INPUT :
    string s = "aab";

    // OUTPUT :
    cout<<min_cut(s)<<endl;

    return 0;
}