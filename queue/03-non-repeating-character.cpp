// PROBLEM: First non-repeating character in a stream
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1


#include<iostream>
#include<queue>
#include<string>

using namespace std;


// SOLUTION
string non_repeating (string a) {
    int count[26] = {0};
    queue<char> q;
    string result;

    for (auto x : a) {
        q.push(x);
        count[x-'a']++;

        if (!q.empty() && count[q.front()-'a']==1)
            result += q.front();
        else if (count[q.front()-'a']>1) {
            while (!q.empty() && count[q.front()-'a']>1)
                q.pop();

            if(!q.empty()) result += q.front();
            else result += '#';
        }
    }

    return result;
}


int main() {
    // INPUT :
    string a = "aabc";

    // OUTPUT :
    cout<<non_repeating(a)<<endl;

    return 0;
}