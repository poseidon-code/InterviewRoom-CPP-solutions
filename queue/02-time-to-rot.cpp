// PROBLEM: Minimum time to rot all oranges
// https://leetcode.com/problems/rotting-oranges/
// https://practice.geeksforgeeks.org/problems/rotten-oranges/0


#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// SOLUTION
int rotting (vector<vector<int>> &grid) {
    queue<vector<int>> q;
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int ct=0, result=-1;

    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] > 0) ct++;
            if (grid[i][j]==2) q.push({i,j});
        }
    }

    while(!q.empty()) {
        result++;
        int size=q.size();

        for (int k=0; k<size; k++) {
            vector<int> cur = q.front();
            ct--;
            q.pop();

            for (int i=0; i<4; i++) {
                int x=cur[0]+dir[i][0];
                int y=cur[1]+dir[i][1];

                if (x>=grid.size() || x<0 || y>=grid[0].size() || y<0 || grid[x][y]!=1)
                    continue;
                
                grid[x][y]=2;
                q.push({x,y});
            }
        }
    }

    if (ct==0) return max(0, result);
    return -1;
}


int main() {
    // INPUT :
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};

    // OUTPUT :
    cout<<rotting(grid)<<endl;

    return 0;
}