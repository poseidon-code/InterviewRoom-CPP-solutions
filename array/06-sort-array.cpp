// PROBLEM: Sort an array of 0s, 1s and 2s
// https://leetcode.com/problems/sort-colors/
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
void sort_array(vector<int> &nums) {
    int l=0;
    int m=0;
    int h=nums.size()-1;

    while (m<=h) {
        if (nums[m]==0) {
            swap(nums[m++], nums[l++]);
        } else if (nums[m]==1) {
            m++;
        } else {
            swap(nums[m], nums[h--]);
        }
    }

    cout<<"["; for (auto i : nums) cout<<i<<" "; cout<<"\b]"<<endl;
}

int main() {
    // INPUT :
    vector<int> nums = {2,0,2,1,1,0};

    // OUTPUT :
    sort_array(nums);

    return 0;
}