// PROBLEM: Next greater element
// https://leetcode.com/problems/next-greater-element-ii/
// https://practice.geeksforgeeks.org/problems/next-larger-element/0


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
vector<int> next_greater (vector<int> &nums) {
    int n = nums.size();
    vector<int> stack, result(n, -1);

    for (int i=0; i<n*2; i++) {
        while (stack.size() && nums[stack.back()] < nums[i%n]) {
            result[stack.back()] = nums[i%n];
            stack.pop_back();
        }
        stack.push_back(i%n);
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {1,2,3,4,3};

    // OUTPUT :
    auto result = next_greater(nums);
    cout<<"["; for (auto n : result) cout<<n<<" "; cout<<"\b]"<<endl;

    return 0;
}