// PROBLEM: Find whether the pat exists
// https://www.interviewbit.com/problems/cycle-in-undirected-graph/
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?category[]=Graph&category[]=Graph&page=1&query=category[]Graphpage1category[]Graph

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
bool path (vector<vector<int>>& grid, int i, int j) {
    if (i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0) return false;
    if (grid[i][j]==2) return true;
    grid[i][j] = 0;

    return path(grid, i+1, j) || path(grid, i-1, j) || path(grid, i, j+1) || path(grid, i, j-1);
}

bool is_possible (vector<vector<int>>& grid) {
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == 1)
                return path(grid, i, j);
        }
    }

    return false;
}


int main() {
    // INPUT :
    vector<vector<int>> grid = {{1,3},{3,2}};

    // OUTPUT :
    is_possible(grid) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}