// PROBLEM: Find duplicate number
// https://leetcode.com/problems/find-the-duplicate-number/


#include<iostream>
#include<vector>

using namespace std;


// SOLUTION
int duplicate(vector<int> &nums) {
    for (int i = 0; i<nums.size(); i++) {
        int index = abs(nums[i]) - 1;

        nums[index] *= -1;

        if (nums[index]>0)
            return abs(nums[i]);
    }

    return -1;
}


int main() {
    // INPUT :
    vector<int> nums = {3,1,3,4,2};

    // OUTPUT :
    cout<<duplicate(nums)<<endl;

    return 0;
}