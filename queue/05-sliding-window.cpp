// PROBLEM: Sliding window maximum
// https://leetcode.com/problems/sliding-window-maximum/
// https://www.interviewbit.com/problems/sliding-window-maximum/


#include<iostream>
#include<vector>
#include<deque>

using namespace std;


// SOLUTION
vector<int> maximum (vector<int> &nums, int k) {
    deque<int> buffer;
    vector<int> result;

    for (int i=0; i<nums.size(); i++) {
        while (!buffer.empty() && nums[i]>=nums[buffer.back()])
            buffer.pop_back();
        buffer.push_back(i);

        if (i>=k-1)
            result.push_back(nums[buffer.front()]);
        if (buffer.front()<=i-k+1)
            buffer.pop_front();
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    // OUTPUT :
    auto result = maximum(nums, k);
    cout<<"["; for (auto m : result) cout<<m<<" "; cout<<"\b]"<<endl;

    return 0;
}