// PROBLEM: Climbing stairs
// https://leetcode.com/problems/climbing-stairs/

#include<iostream>

using namespace std;

// SOLUTION
int climb_stairs (int n) {
    int a=1, b=1;
    while (n--)
        a = (b+=a) - a;
    return a;
}


int main() {
    // INPUT :
    int n = 3;

    // OUTPUT :
    cout<<climb_stairs(n)<<endl;

    return 0;
}