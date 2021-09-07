// PROBLEM: Next permutation
// https://leetcode.com/problems/next-permutation/
// https://www.interviewbit.com/problems/next-permutation/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// SOLUTION
void next_permutation (vector<int> &nums) {
    int n = nums.size();
    int k, l;

    for (k=n-2; k>=0; k--)
        if (nums[k] < nums[k+1]) break;
    
    if (k<0) {
        reverse(nums.begin(), nums.end());
    } else {
        for (l=n-1; l>k; l--)
            if (nums[l] > nums[k]) break;
        
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
}


int main() {
    // INPUT :
    vector<int> nums = {1,1,5};

    // OUTPUT :
    next_permutation(nums);
    cout<<"["; for (int i : nums) cout<<i<<" "; cout<<"\b]"<<endl;

    return 0;
}
