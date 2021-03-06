// PROBLEM: Majority element
// https://leetcode.com/problems/majority-element/
// https://www.interviewbit.com/problems/majority-element/
// https://practice.geeksforgeeks.org/problems/majority-element/0

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int majority_element (vector<int> &nums) {
    int major=nums[0];
    int count=1;

    for (int n : nums) {
        if (count == 0) {
            count++;
            major = n;
        }
        else if (major == n)
            count++;
        else
            count--;
    }

    return major;
}


int main() {
    // INPUT :
    vector<int> nums = {3,2,3};

    // OUTPUT :
    cout<<majority_element(nums)<<endl;

    return 0;
}