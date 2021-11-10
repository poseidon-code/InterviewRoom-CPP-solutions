// PROBLEM: Find top k frequent elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// SOLUTION
vector<int> k_frequent (vector<int> &nums, int k) {
    unordered_map<int, int> counts;
    for (auto i : nums) ++counts[i];

    vector<vector<int>> buckets(nums.size()+1);
    for (auto p : counts)
        buckets[p.second].push_back(p.first);

    vector<int> result;
    for (int i = buckets.size()-1; i>=0 && result.size()<k; i--) {
        for (auto i : buckets[i]) {
            result.push_back(i);
            if (result.size()==k) break;
        }
    }

    return result;
}


int main() {
    // INPUT :
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    // OUTPUT :
    auto result = k_frequent(nums, k);
    cout<<"["; for (auto x : result) cout<<x<<" "; cout<<"\b]"<<endl;

    return 0;
}