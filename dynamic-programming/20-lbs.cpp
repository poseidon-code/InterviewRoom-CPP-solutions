// PROBLEM: Longest Bitonic Subsequence
// https://www.interviewbit.com/problems/length-of-longest-subsequence/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
int lbs (vector<int> A) {
    int n = A.size();
    
    vector<int> lis(n, 1);
    for (int i=1; i<n; i++)
        for (int j=0; j<i; j++)
            if (A[i]>A[j] && lis[i]<lis[j]+1)
                lis[i] = lis[j]+1;

    vector<int> lds(n, 1);
    for (int i=n-2; i>=0; i--)
        for (int j=n-1; j>i; j--)
            if (A[i]>A[j] && lds[i]<lds[j]+1)
                lds[i] = lds[j]+1;

    int result = lis[0] + lds[0] - 1;
    for (int i=1; i<n; i++)
        if (lis[i]+lds[i]-1 > result)
            result = lis[i] + lds[i] -1;
    
    return result;
}


int main() {
    // INPUT :
    vector<int> A = {1,2,1};

    // OUTPUT :
    cout<<lbs(A)<<endl;

    return 0;
}