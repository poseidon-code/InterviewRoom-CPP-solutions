// PROBLEM: Trapping rain water
// https://leetcode.com/problems/trapping-rain-water/
// https://www.interviewbit.com/problems/rain-water-trapped/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int trap (vector<int> &height) {
    int h1 = 0, h2 = 0;
    int total = 0;

    for (int l=0, r=height.size() - 1; l<r;) {
        if (height[l]<height[r]) {
            h1 = max(h1, height[l]);
            total += h1 - height[l++];
        } else {
            h2 = max(h2, height[r]);
            total += h2 - height[r--];
        }
    }

    return total;
}


int main() {
    // INPUT :
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    // OUTPUT :
    cout<<trap(height)<<endl;

    return 0;
}