// PROBLEM: Min cost climbing stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int min_cost (vector<int> &cost) {
    for (int i=2; i<cost.size(); i++)
        cost[i] += min(cost[i-1], cost[i-2]);
    
    return min(cost[cost.size()-1], cost[cost.size()-2]);
}


int main() {
    // INPUT :
    vector<int> cost = {10,15,20};

    // OUTPUT :
    cout<<min_cost(cost)<<endl;

    return 0;
}