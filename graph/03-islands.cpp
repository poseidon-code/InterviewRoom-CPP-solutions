// PROBLEM: Number of islands
// https://leetcode.com/problems/number-of-islands/
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/?category[]=Graph&category[]=Graph&page=1&query=category[]Graphpage1category[]Graph

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int dfs (vector<vector<char>>& grid, int i, int j) {
    if (i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0') return 0;
    
    grid[i][j] = '0';
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
    return 1;
}

int islands (vector<vector<char>>& grid) {
    int islands = 0;
    
    for (int i=0; i<grid.size(); i++)
        for (int j=0; j<grid[i].size(); j++)
            islands += dfs(grid, i, j);
    
    return islands;
}


int main() {
    // INPUT :
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // OUTPUT :
    cout<<islands(grid)<<endl;

    return 0;
}