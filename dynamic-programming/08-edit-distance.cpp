// PROBLEM: Edit distance
// https://leetcode.com/problems/edit-distance/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// SOLUTION
int edit_distance (string word1, string word2) {
    int m = word1.size(), n = word2.size(), pre;
    vector<int> result(n+1, 0);
    for (int i=1; i<=n; i++) result[i] = i;

    for (int i=1; i<=m; i++) {
        pre = result[0];
        result[0] = i;

        for (int j=1; j<=n; j++) {
            int temp = result[j];
            if (word1[i-1]==word2[j-1])
                result[j] = pre;
            else 
                result[j] = min(pre, min(result[j-1], result[j])) + 1;
            pre = temp;
        }
    }

    return result[n];
}


int main() {
    // INPUT :
    string word1 = "horse";
    string word2 = "ros";

    // OUTPUT :
    cout<<edit_distance(word1, word2)<<endl;

    return 0;
}