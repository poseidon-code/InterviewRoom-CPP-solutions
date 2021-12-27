// PROBLEM: Topological Sort (Course Schedule 2)
// https://leetcode.com/problems/course-schedule-ii/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// SOLUTION
vector<int> find_order (int courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> G(courses);
        vector<int> ans, indegree(courses);
        for (auto& pre : prerequisites) 
            G[pre[1]].push_back(pre[0]),
            indegree[pre[0]]++;

        queue<int> q;
        for (int i=0; i<courses; i++)
            if (indegree[i] == 0) q.push(i);
        
        while (size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);
            
            for (auto nextCourse : G[cur])
                if (--indegree[nextCourse] == 0)
                    q.push(nextCourse);
        }

        if (size(ans) == courses) return ans;
        return {};
}


int main() {
    // INPUT :
    int courses = 2;
    vector<vector<int>> prerequisites = {{1,0}};

    // OUTPUT :
    auto result = find_order(courses, prerequisites);
    cout<<"["; for (auto x : result) cout<<x<<", "; cout<<"\b\b]"<<endl;

    return 0;
}