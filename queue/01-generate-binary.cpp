// PROBLEM: Generate binary numbers from 1 to n  
// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

#include<iostream>
#include<queue>

using namespace std;


// SOLUTION
void generate (int n) {
    queue<string> q;
    q.push("1");

    while (n--) {
        string s1 = q.front();
        q.pop();
        cout<<s1<<" ";

        string s2 = s1;

        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    cout<<endl;
}

int main() {
    // INPUT :
    int n = 10;

    // OUTPUT :
    generate(n);

    return 0;
}