// PROBLEM: Find kth smallest element in matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// SOLUTION
int k_smallest (vector<vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    int result;

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for (int r=0; r<min(m, k); r++)
        pq.push({matrix[r][0], r, 0});

    for (int i=1; i<=k; i++) {
        auto top = pq.top();
        pq.pop();
        int r = top[1];
        int c = top[2];
        result = top[0];
        if (c+1<n) pq.push({matrix[r][c+1], r, c+1});
    }

    return result;
}


int main() {
    // INPUT :
    vector<vector<int>> matrix = {{1,5,9}, {10,11,13}, {12,13,15}};
    int k = 8;
    
    // OUTPUT :
    cout<<k_smallest(matrix, k)<<endl;

    return 0;
}