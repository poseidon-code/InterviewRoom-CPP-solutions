// PROBLEM: Merge overlapping intervals
// https://leetcode.com/problems/merge-intervals/
// https://www.interviewbit.com/problems/merge-intervals/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// SOLUTION
vector<vector<int>> merge_intervals (vector<vector<int>> &intervals) {
    if (intervals.size()<=1) return intervals;

    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0]<=b[0];});

    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i=1; i<intervals.size(); i++) {
        if (result.back()[1] < intervals[i][0])
            result.push_back(intervals[i]);
        else
            result.back()[1] = max(result.back()[1], intervals[i][1]);
    }

    return result;    
}


int main() {
    // INPUT :
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    // OUTPUT :
    auto mergeintervals = merge_intervals(intervals);
    cout<<"[";
    for (int i=0; i<mergeintervals.size(); i++) {
        cout<<"[";
        for (int j=0; j<mergeintervals[i].size(); j++)
            cout<<mergeintervals[i][j]<<" ";
        cout<<"\b], ";
    }
    cout<<"\b\b]"<<endl;

    return 0;
}