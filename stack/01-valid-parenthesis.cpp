// PROBLEM: Valid parenthesis
// https://leetcode.com/problems/valid-parentheses/


#include<iostream>
#include<string>
#include<stack>

using namespace std;

// SOLUTION
bool is_valid (string s) {
    stack<char> parenthesis;

    for (auto &c : s) {
        switch(c) {
            case '{': parenthesis.push('}'); break;
            case '[': parenthesis.push(']'); break;
            case '(': parenthesis.push(')'); break;
            default:
                if (parenthesis.size()==0 || c!=parenthesis.top())
                    return false;
                else parenthesis.pop();
        }
    }

    return parenthesis.empty();
}


int main() {
    // INPUT :
    string s = "()[]{}";

    // OUTPUT :
    cout<<(is_valid(s) == 1 ? "true" : "false")<<endl;

    return 0;
}