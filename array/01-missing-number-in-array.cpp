// PROBLEM: Missong number in array
// https://leetcode.com/problems/missing-number/
// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int missing_number(vector<int>& nums) {
    int result = nums.size();
    int i=0;

    for (int num:nums) {
        result ^= num^i;
        i++;
    }

    return result;
}

int main() {
    // INPUT :
    vector<int> nums = {3,1,0,2};

    // OUTPUT :
    cout<<missing_number(nums)<<endl;

    return 0;
}