// PROBLEM: Cycle in a directed graph
// https://leetcode.com/problems/course-schedule/
// https://www.interviewbit.com/problems/cycle-in-directed-graph/


#include<iostream>
#include<vector>

using namespace std;

// SOLUTION
bool can_finish (int courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> G(courses);
    vector<int> degree(courses, 0), bfs;
    for (auto& e : prerequisites)
        G[e[1]].push_back(e[0]), degree[e[0]]++;
    
    for (int i = 0; i < courses; ++i)
        if (!degree[i]) bfs.push_back(i);
    
    for (int i = 0; i < bfs.size(); ++i)
        for (int j: G[bfs[i]])
            if (--degree[j] == 0) bfs.push_back(j);
    
    return bfs.size() == courses;
}


int main() {
    // INPUT :
    int courses = 5;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};

    // OUTPUT :
    can_finish(courses, prerequisites) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}