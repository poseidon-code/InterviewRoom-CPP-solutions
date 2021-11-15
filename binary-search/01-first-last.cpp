// PROBLEM: Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
vector<int> search_range (vector<int> &nums, int target) {
    int i=0, j=nums.size()-1;
    vector<int> result(2, -1);

    while (i<j) {
        int mid = (i+j)/2;
        if (nums[mid]<target) i = mid+1;
        else j = mid;
    }
    if (nums[i] != target) return result;
    else result[0] = i;

    j = nums.size()-1;
    while (i<j) {
        int mid = (i+j)/2 + 1;
        if (nums[mid]>target) j = mid-1;
        else i = mid;
    }
    result[1] = j;
    
    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    // OUTPUT :
    auto result = search_range(nums, target);
    cout<<"["; for (auto x : result) cout<<x<<" "; cout<<"\b]"<<endl;

    return 0;
}