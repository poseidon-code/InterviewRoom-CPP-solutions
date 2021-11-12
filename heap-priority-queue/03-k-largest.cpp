// PROBLEM: Find kth largest element in a stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// SOLUTION
priority_queue<int, vector<int>, greater<int>> pq;
int qsize;

void k_largest (int k, vector<int> &nums) {
    qsize=k;
    for(int i=0;i<nums.size();i++) {
        pq.push(nums[i]);
        if(pq.size()>k) pq.pop();
    }
}

int add(int val) {
    pq.push(val);
    if(pq.size()>qsize) pq.pop();
    return pq.top();
}


int main() {
    // INPUT :
    int k = 3;
    vector<int> nums = {4,5,8,2};
    vector<int> input = {3,5,10,9,4};
    
    // OUTPUT :
    k_largest(k, nums);
    for (auto i : input) {
        cout<<add(i)<<endl;
    }

    return 0;
}