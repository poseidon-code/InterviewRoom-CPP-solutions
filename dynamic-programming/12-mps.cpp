// PROBLEM: Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int mps (vector<int>& nums) {
    int n=nums.size(), l=0, r=0;
    int result = nums[0];

    for (int i=0; i<n; i++) {
        l = (l ? l : 1) * nums[i];
        r = (r ? r : 1) * nums[n-1-i];
        result = max(result, max(l, r));
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {2,3,-2,4};

    // OUTPUT :
    cout<<mps(nums)<<endl;

    return 0;
}