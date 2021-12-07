// PROBLEM: Coin change
// https://leetcode.com/problems/coin-change/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int change (vector<int>& coins, int amount) {
    vector<int> need(amount+1, amount+1);
    need[0] = 0;

    for (int c : coins)
        for (int a=c; a<=amount; a++) 
            need[a] = min(need[a], need[a-c]+1);
    
    return need.back() > amount ? -1 : need.back();
}


int main() {
    // INPUT :
    vector<int> coins = {1,2,5};
    int amount = 11;

    // OUTPUT :
    cout<<change(coins, amount)<<endl;

    return 0;
}