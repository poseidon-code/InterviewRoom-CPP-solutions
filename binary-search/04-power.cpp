// PROBLEM: Power(x,n)
// https://leetcode.com/problems/powx-n/
// https://www.interviewbit.com/problems/implement-power-function/

#include<iostream>

using namespace std;

// SOLUTION
double power (double x, int n) {
    if (n==0) return 1;
    if (n==INT32_MIN) {
        x = x*x;
        n = n/2;
    }
    if (n<0) {
        n = -n;
        x = 1/x;
    }

    return (n%2==0) ? power(x*x, n/2) : x * power(x*x, n/2);
}


int main() {
    // INPUT :
    double x = 2.10000;
    int n = 3;

    // OUTPUT :
    cout<<power(x, n)<<endl;

    return 0;
}