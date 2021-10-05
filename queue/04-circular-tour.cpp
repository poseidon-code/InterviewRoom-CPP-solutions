// PROBLEM: Circular tour
// https://leetcode.com/problems/gas-station/
// https://practice.geeksforgeeks.org/problems/circular-tour/1


#include<iostream>
#include<vector>

using namespace std;


// SOLUTION
int circular_tour(vector<int> &gas, vector<int> &cost) {
    int start=0, total=0, tank=0;

    for (int i=0; i<gas.size(); i++) {
        tank += gas[i]-cost[i];
        if (tank < 0) {
            start = i+1;
            total += tank;
            tank=0;
        }
    }

    return (total + tank) < 0 ? -1 : start;
}


int main() {
    // INPUT :
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    // OUTPUT :
    cout<<circular_tour(gas, cost)<<endl;

    return 0;
}