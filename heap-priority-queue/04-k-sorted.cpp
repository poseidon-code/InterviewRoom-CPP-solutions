// PROBLEM: Sort a nearly sorted array
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// SOLUTION
vector<int> k_sorted (vector<int> &nums, int k) {
    int size = nums.size()==k ? k : k+1;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<size; i++)
        pq.push(nums[i]);

    int index = 0;
    for (int i=k+1; i<nums.size(); i++) {
        nums[index++] = pq.top();
        pq.pop();
        pq.push(nums[i]);
    }

    while (!pq.empty()) {
        nums[index++] = pq.top();
        pq.pop();
    }

    return nums;
}


int main() {
    // INPUT :
    vector<int> nums = {2,6,3,12,56,8};
    int k = 3;
    
    // OUTPUT :
    auto result = k_sorted(nums, k);
    cout<<"["; for (auto i : result) cout<<i<<" "; cout<<"\b]"<<endl;

    return 0;
}