// PROBLEM: Coin sum infinite
// https://www.interviewbit.com/problems/coin-sum-infinite/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int coin_sum (vector<int> &s, int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i=0; i<s.size(); i++) {
        for (int j=s[i]; j<=n; j++) {
            dp[j] += dp[j-s[i]];
        }
    }

    return dp[n];
}


int main() {
    // INPUT :
    vector<int> s = {1,2,3};
    int n = 4;

    // OUTPUT :
    cout<<coin_sum(s, n)<<endl;

    return 0;
}