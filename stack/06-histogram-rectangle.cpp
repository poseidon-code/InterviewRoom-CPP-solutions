// PROBLEM: Largest rectangle in a histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// SOLUTION
int rectangle (vector<int> &heights) {
    stack<int> stack;
    int l = heights.size();
    int max_area = 0;

    for (int i=0; i<=l; i++) {
        int h = i==l ? 0 : heights[i];

        if (stack.empty() || h>=heights[stack.top()])
            stack.push(i);
        else {
            int tp = stack.top();
            stack.pop();
            max_area = max(max_area, heights[tp]*(stack.empty() ? i : i-1-stack.top()));
            i--;
        }
    }

    return max_area;
}

int main() {
    // INPUT :
    vector<int> heights = {2,1,5,6,2,3};

    // OUTPUT :
    cout<<rectangle(heights)<<endl;

    return 0;
}