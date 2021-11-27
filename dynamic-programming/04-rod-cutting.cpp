// PROBLEM: Rod cutting
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int cutting (vector<int> &price, int n) {
    vector<int> result(n+1);
    result[0] = 0;

    for (int i=1; i<=n; i++) {
        int max_val = INT16_MIN;
        for (int j=0; j<i; j++)
            max_val = max(max_val, price[j] + result[i-j-1]);
        result[i] = max_val;
    }

    return result[n];
}


int main() {
    // INPUT :
    vector<int> price = {1,5,8,9,10,17,17,20};
    int n = 8;

    // OUTPUT :
    cout<<cutting(price, n)<<endl;

    return 0;
}