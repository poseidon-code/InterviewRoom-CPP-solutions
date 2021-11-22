// PROBLEM: Matrix search
// https://leetcode.com/problems/search-a-2d-matrix/
// https://www.interviewbit.com/problems/matrix-search/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
bool matrix_search (vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m=matrix.size(), n=matrix[0].size();
    int start=0, end=m*n-1;

    while (start <= end) {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        
        if(target < e) end = mid - 1;
        else if (target > e) start = mid + 1;
        else return true;
    }

    return false;
}


int main() {
    // INPUT :
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 3;

    // OUTPUT :
    matrix_search(matrix, target) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}