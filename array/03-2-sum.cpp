// PROBLEM: 2 sum
// https://leetcode.com/problems/two-sum/
// https://www.interviewbit.com/problems/2-sum/
// https://practice.geeksforgeeks.org/problems/key-pair/0

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// SOLUTION
vector<int> two_sum (vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (int i=0;; i++) {
        auto it = map.find(target - nums[i]);

        if (it != map.end())
            return {it->second, i};
        
        map[nums[i]] = i;
    }
}


int main() {
    // INPUT :
    vector<int> nums = {2,7,11,15};
    int target = 9;

    // OUTPUT :
    auto twosum = two_sum(nums, target);
    cout<<"["<<twosum[0]<<", "<<twosum[1]<<"]"<<endl;

    return 0;
}