// PROBLEM: Subarray with given sum
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
vector<int> subarray_sum(int A[], int S, int N) {
    int sum = A[0];
    int start = 0;
    int end;

    for (end=1; end<=N; end++) {
        while (sum>S && start<end-1) {
            sum = sum - A[start];
            start++;
        }
        
        if (sum == S)
            return {start+1, end};

        if (end < N)
            sum = sum + A[end];
    }

    return {-1};
}

int main() {
    // INPUT :
    int A[] = {1,2,3,7,5};
    int S=12;
    int N=sizeof(A)/sizeof(A[0]);

    // OUTPUT :
    auto ss = subarray_sum(A,S,N);
    for (int p : ss) cout<<p<<" ";
    cout<<endl;

    return 0;
}