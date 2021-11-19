// PROBLEM: Find square root of a number
// https://leetcode.com/problems/sqrtx/
// https://www.interviewbit.com/problems/square-root-of-integer/

#include<iostream>

using namespace std;

// SOLUTION
int sqrt (int x) {
    long r = x;
    while (r*r > x)
        r = (r + x/r)/2;
    return r;
}


int main() {
    // INPUT :
    int x = 8;

    // OUTPUT :
    cout<<sqrt(x)<<endl;

    return 0;
}