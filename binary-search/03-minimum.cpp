// PROBLEM: Find minimum in a rotated sorted array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int minimum (vector<int> &nums) {
    int start=0, end=nums.size()-1;
    
    while (start<end) {
        if (nums[start]<nums[end])
            return nums[start];
        
        int mid = (start+end)/2;

        if (nums[mid]>=nums[start]) start = mid+1;
        else end = mid;
    }

    return nums[start];
}


int main() {
    // INPUT :
    vector<int> nums = {3,4,5,1,2};

    // OUTPUT :
    cout<<minimum(nums)<<endl;

    return 0;
}