// PROBLEM: Largest number formed from an array
// https://leetcode.com/problems/largest-number/
// https://www.interviewbit.com/problems/largest-number/
// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// SOLUTION
string largest_formed(vector<int> &nums) {
    vector<string> s;
    for (auto i : nums) s.push_back(to_string(i));

    sort(begin(s), end(s), 
        [](string &a, string &b) {
            return a+b > b+a;
        }
    );

    string result;
    for (auto i : s) result+=i;
    
    return result;    
}


int main() {
    // INPUT :
    vector<int> nums = {0,0};

    // OUTPUT :
    cout<<largest_formed(nums)<<endl;

    return 0;
}