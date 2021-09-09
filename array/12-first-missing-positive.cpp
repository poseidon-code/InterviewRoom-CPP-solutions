// PROBLEM: First missing positive
// https://leetcode.com/problems/first-missing-positive/
// https://www.interviewbit.com/problems/first-missing-integer/


#include<iostream>
#include<vector>

using namespace std;


// SOLUTION
int missing_positive (vector<int> &nums) {
    int n = nums.size();

    for (int i=0; i<n; i++)
        while (nums[i]>0 && nums[i]<=n && nums[nums[i]-1] != nums[i])
            swap(nums[i], nums[nums[i]-1]);

    for (int i=0; i<n; i++)
        if (nums[i] != i+1)
            return i+1;
    
    return n+1;
}


int main() {
    // INPUT :
    vector<int> nums = {7,8,9,11,12,-3};

    // OUTPUT :
    cout<<missing_positive(nums)<<endl;

    return 0;
}