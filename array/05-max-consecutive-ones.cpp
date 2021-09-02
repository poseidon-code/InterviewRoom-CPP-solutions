// PROBLEM: Max consecutive ones
// https://leetcode.com/problems/max-consecutive-ones/
// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int max_ones (vector<int> &nums) {
    int max1s=0;
    int count=0;

    for (int n : nums) {
        if(n==1) {
            count++;
            max1s = max(count, max1s);
        } else {
            count = 0;
        }
    }

    return max1s;
}


int main() {
    // INPUT :
    vector<int> nums = {1,1,0,1,1,1};

    // OUTPUT :
    cout<<max_ones(nums)<<endl;

    return 0;
}