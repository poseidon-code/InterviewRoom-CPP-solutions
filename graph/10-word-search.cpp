// PROBLEM: Word Search
// https://leetcode.com/problems/word-search/
// https://www.interviewbit.com/problems/word-search-board/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// SOLUTION
bool dfs (vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size()) return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[0]) return false;

    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    
    bool result =  dfs(board, i-1, j, s)
                || dfs(board, i+1, j, s)
                || dfs(board, i, j-1, s)
                || dfs(board, i, j+1, s);
    board[i][j] = c;
    
    return result;
}

bool exist (vector<vector<char>>& board, string word) {
    for (int i=0; i<board.size(); i++)
        for (int j=0; j<board[0].size(); j++)
            if (dfs(board, i, j, word))
                return true;
    
    return false;
}


int main() {
    // INPUT :
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    // OUTPUT :
    exist(board, word) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}