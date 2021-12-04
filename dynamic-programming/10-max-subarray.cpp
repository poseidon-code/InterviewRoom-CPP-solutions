// PROBLEM: Maximum subarray
// https://leetcode.com/problems/maximum-subarray/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int max_subarray (vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int result = dp[0];
    
    for (int i=1; i<n; i++) {
        dp[i] = nums[i] + (dp[i-1]>0 ? dp[i-1] : 0);
        result = max(result, dp[i]);
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {5,4,-1,7,8};

    // OUTPUT :
    cout<<max_subarray(nums)<<endl;

    return 0;
}