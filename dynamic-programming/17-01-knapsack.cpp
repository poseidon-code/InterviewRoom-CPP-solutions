// PROBLEM: 01 Knapsack
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int knapsack (int W, vector<int>& weights, vector<int> values, int N) {
    vector<int> dp(W+1, 0);

    for (int i=1; i<N+1; i++) {
        for (int w=W; w>=0; w--) {
            if (weights[i-1] <= w)
                dp[w] = max(dp[w], dp[w - weights[i-1]] + values[i-1]);
        }
    }

    return dp[W];
}


int main() {
    // INPUT :
    int N = 3;
    int W = 4;
    vector<int> values = {1,2,3};
    vector<int> weights = {4,5,1};

    // OUTPUT :
    cout<<knapsack(W, weights, values, N)<<endl;

    return 0;
}