// PROBLEM: Spiral matrix
// https://leetcode.com/problems/spiral-matrix/
// https://www.interviewbit.com/problems/spiral-order-matrix-i/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
vector<int> spiral_matrix(vector<vector<int>> &matrix) {
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<int> steps = {n, m-1};

    int id = 0;
    int ir = 0;
    int ic = -1;

    while (steps[id%2]) {
        for (int i=0; i<steps[id%2]; i++) {
            ir += directions[id][0];
            ic += directions[id][1];
            result.push_back(matrix[ir][ic]);
        }

        steps[id%2]--;
        id = (id+1) % 4;
    }
    
    return result;
}

int main() {
    // INPUT :
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    // OUTPUT :
    auto spiralmatrix = spiral_matrix(matrix);
    cout<<"["; for (int i : spiralmatrix) cout<<i<<" "; cout<<"\b]"<<endl;

    return 0;
}