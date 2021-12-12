// PROBLEM: Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
bool partition (vector<int>& nums) {
    int sum =0;
    for (int n : nums) sum += n;
    if ((sum & 1)==1) return false;
    sum /=2;

    int n = nums.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;

    for (int x : nums)
        for (int i=sum; i>0; i--)
            if (i >= x)
                dp[i] = dp[i] || dp[i-x];

    return dp[sum];
}


int main() {
    // INPUT :
    vector<int> nums = {1,5,11,5};

    // OUTPUT :
    partition(nums) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}