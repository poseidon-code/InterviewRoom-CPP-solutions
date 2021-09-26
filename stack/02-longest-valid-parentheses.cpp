// PROBLEM: Length of longest valid parentheses
// https://leetcode.com/problems/longest-valid-parentheses/


#include<iostream>
#include<string>
#include<stack>

using namespace std;

// SOLUTION
int longest_length (string s) {
    stack<int> parentheses;
    parentheses.push(-1);
    int result = 0;

    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') {
            parentheses.push(i);
        } else {
            parentheses.pop();
            
            if (parentheses.empty())
                parentheses.push(i);
            else
                result = max(result, i - parentheses.top());
        }
    }

    return result;
}


int main() {
    // INPUT :
    string s = ")()())";

    // OUTPUT :
    cout<<longest_length(s)<<endl;

    return 0;
}