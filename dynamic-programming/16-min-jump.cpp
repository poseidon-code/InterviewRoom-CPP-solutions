// PROBLEM: Minimum jump to reach end
// https://leetcode.com/problems/jump-game-ii/
// https://www.interviewbit.com/problems/min-jumps-array/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int jump (vector<int>& nums) {
    int jumps=0;
    int ce = 0, cf = 0;

    for (int i=0; i<nums.size()-1; i++) {
        cf = max(cf, i + nums[i]);

        if (i == ce) {
            jumps++;
            ce = cf;
        }
    }

    return jumps;
}


int main() {
    // INPUT :
    vector<int> nums = {2,3,1,1,4};

    // OUTPUT :
    cout<<jump(nums)<<endl;

    return 0;
}