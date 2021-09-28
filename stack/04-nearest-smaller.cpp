// PROBLEM: Nearest smaller
// https://www.interviewbit.com/problems/nearest-smaller-element/


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// SOLUTION
vector<int> nearest_smaller (vector<int> &nums) {
    vector<int> result = {-1};
    stack<int> stack;
    stack.push(nums[0]);

    for (int i=1; i<nums.size(); i++) {
        while (!stack.empty() && stack.top() >= nums[i])
            stack.pop();
        
        result.push_back(stack.empty() ? -1 : stack.top());
        stack.push(nums[i]);
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {4,5,2,10,8};

    // OUTPUT :
    auto result = nearest_smaller(nums);
    cout<<"["; for (auto n : result) cout<<n<<" "; cout<<"\b]"<<endl;

    return 0;
}