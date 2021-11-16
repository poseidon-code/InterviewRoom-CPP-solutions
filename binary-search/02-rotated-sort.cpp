// PROBLEM: Serach in a rotated sorted array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://www.interviewbit.com/problems/rotated-sorted-array-search/
// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int search_rotated (vector<int> &nums, int target) {
    int n = nums.size();
    int l=0, h=n-1;
    
    while (l<h) {
        int m = (l+h)/2;
        if (nums[m]>nums[h]) l = m+1;
        else h = m;
    }

    int rot=l;
    l=0;
    h=n-1;
    while (l<=h) {
        int m = (l+h)/2;
        int rm = (m+rot)%n;
        if (nums[rm]==target) return rm;
        if (nums[rm]<target) l = m+1;
        else h = m-1;
    }

    return -1;
}


int main() {
    // INPUT :
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    // OUTPUT :
    cout<<search_rotated(nums, target)<<endl;

    return 0;
}