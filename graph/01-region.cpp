// PROBLEM: Region in binary matrix
// https://www.interviewbit.com/problems/region-in-binarymatrix/
// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
void dfs(vector<vector<int>>& grid, int i, int j, int& result) {
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
    
    grid[i][j] = 0;
    result++;
    dfs(grid, i+1, j,   result);
    dfs(grid, i-1, j,   result);
    dfs(grid, i,   j+1, result);
    dfs(grid, i,   j-1, result);
    dfs(grid, i+1, j+1, result);
    dfs(grid, i-1, j+1, result);
    dfs(grid, i+1, j-1, result);
    dfs(grid, i-1, j-1, result);
}

int region (vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int maxarea=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int result = 0;
            if (grid[i][j] == 1) {
                dfs(grid, i, j, result);
                maxarea = max(maxarea, result);
            }
        }
    }

    return maxarea;
}


int main() {
    // INPUT :
    vector<vector<int>> grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}};

    // OUTPUT :
    cout<<region(grid)<<endl;

    return 0;
}