// PROBLEM: Longest common substring
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int lcss (vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(), n=nums2.size();
    vector<int> dp(n+1, 0);
    int result = 0;

    for (int i=1; i<=m; i++) {
        for (int j=n; j>0; j--) {
            if (nums1[i-1] == nums2[j-1]) {
                dp[j] = 1 + dp[j-1];
                result = max(result, dp[j]);
            } else {
                dp[j] = 0;
            }
        }
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};

    // OUTPUT :
    cout<<lcss(nums1, nums2)<<endl;

    return 0;
}