// PROBLEM: House Robber
// https://leetcode.com/problems/house-robber/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int rob (vector<int>& nums) {
    int a=0, b=0, n=nums.size();

    for (int i=0; i<n; i++) {
        if (i%2==0)
            a = max(a+nums[i], b);
        else
            b = max(a, b+nums[i]);
    }

    return max(a, b);
}


int main() {
    // INPUT :
    vector<int> nums = {1,2,3,1};

    // OUTPUT :
    cout<<rob(nums)<<endl;

    return 0;
}