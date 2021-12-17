// PROBLEM: Burst Baloons (Matrix Chain Multiplication)
// https://leetcode.com/problems/burst-balloons/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int max_coins (vector<int>& nums) {
    int N[nums.size() + 2];
    int n = 1;
    for (int x : nums) if (x>0) N[n++]=x;
    N[0] = N[n++] = 1;


    int dp[n][n] = {};
    
    for (int k=2; k<n; ++k) {
        for (int l=0; l<n-k; ++l) {
            int r = l+k;
            for (int i=l+1; i<r; ++i)
                dp[l][r] = max(dp[l][r], N[l] * N[i] * N[r] + dp[l][i] + dp[i][r]);
        }
    }

    return dp[0][n-1];
}


int main() {
    // INPUT :
    vector<int> nums = {3,1,5,8};

    // OUTPUT :
    cout<<max_coins(nums)<<endl;

    return 0;
}