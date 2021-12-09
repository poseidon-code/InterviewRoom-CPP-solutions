// PROBLEM: Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/
// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int rectangle (vector<vector<char>>& matrix) {
    if (matrix.size()==0 || matrix[0].size()==0) return 0;
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;

    vector<int> left(n, 0);
    vector<int> right(n, n-1);
    vector<int> height(n, 0);

    for (int i = 0; i < m; i++) {
        int rB = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                right[j] = min(right[j], rB);
            } else {
                right[j] = n - 1;
                rB = j - 1;
            }
        }

        int lB = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                left[j] = max(left[j], lB);
                height[j]++;
                maxArea = max(maxArea, height[j] * (right[j] - left[j] + 1));
            } else {
                height[j] = 0;
                left[j] = 0;
                lB = j + 1;
            }
        }
    }

    return maxArea;
}


int main() {
    // INPUT :
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    // OUTPUT :
    cout<<rectangle(matrix)<<endl;

    return 0;
}