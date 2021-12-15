// PROBLEM: Word Break
// https://leetcode.com/problems/word-break/
// https://www.interviewbit.com/problems/word-break/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// SOLUTION
bool word_break (string s, vector<string> wordDict) {
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0] = true;
    
    for(int i=0;i<=n;++i)
        for(int j=0;j<i;++j)
            if(dp[j])
                if(find(wordDict.begin(), wordDict.end(), s.substr(j,i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }

    return dp[n];
}


int main() {
    // INPUT :
    string s = "leetcode";
    vector<string> worDict = {"leet", "code"};

    // OUTPUT :
    word_break(s, worDict) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}