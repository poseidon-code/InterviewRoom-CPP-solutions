// PROBLEM: Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
// https://www.interviewbit.com/problems/longest-increasing-subsequence/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int lis (vector<int> &nums) {
    int tails[nums.size()];
    int size = 0;

    for (int x : nums) {
        int i=0, j=size;

        while (i!=j) {
            int m =(i+j)/2;
            if (tails[m]<x) i = m+1;
            else j = m;
        }

        tails[i] = x;
        if (i==size) ++size;
    }

    return size;
}


int main() {
    // INPUT :
    vector<int> nums = {10,9,2,5,3,7,101,18};

    // OUTPUT :
    cout<<lis(nums)<<endl;

    return 0;
}