// PROBLEM: Alien Dictionary
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1/?category[]=Graph&category[]=Graph&page=1&query=category[]Graphpage1category[]Graph

#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

// SOLUTION
string s="";
void bfs (int in[],vector<int> ar[],int N,int cur) {
    queue<int> q;
    for (int i=0; i<N; i++)
        if(in[i]==0)
            q.push(i);
    
    while (!q.empty()) {
        int x=q.front(); q.pop();
        for(auto n : ar[x])  {
            in[n]--;
            if(in[n]==0) q.push(n);
        }
        s+=x+'a';
    }
}

string order (vector<string>& d, int n, int k) {
    int in[1001]={0};
    vector<int> ar[100];
    
    for (int i=0; i<n-1; i++) {
        string s1=d[i];
        string s2=d[i+1];
        
        for(int j=0;j<min(s1.length(),s2.length());j++) {
            if (s1[j]!=s2[j]) {
                ar[s1[j]-'a'].push_back(s2[j]-'a');
                in[s2[j]-'a']++;
                break;
            }
        }
    }
    
    bfs(in,ar,k,0);
    return s;
}


int main() {
    // INPUT :
    vector<string> d = {"caa", "aaa", "aab"};
    int n = 3;
    int k = 3;

    // OUTPUT :
    cout<<order(d, n, k)<<endl;

    return 0;
}