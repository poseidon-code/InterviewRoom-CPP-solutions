// PROBLEM: Word Search 2
// https://leetcode.com/problems/word-search-ii/
// https://practice.geeksforgeeks.org/problems/word-boggle4143/1/?category[]=Graph&category[]=Graph&page=2&query=category[]Graphpage2category[]Graph

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// SOLUTION
struct TrieNode {
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr)
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};

vector<string> result;
void dfs (vector<vector<char>>& board, int r, int c, TrieNode* cur) {
    if (r<0 || r==board.size() || c<0 || c==board[0].size() || board[r][c]=='#' || cur->children[board[r][c]-'a']==nullptr) return;
    vector<int> dirs = {0, 1, 0, -1, 0};

    char orgChar = board[r][c];
    cur = cur->children[orgChar-'a'];
    if (cur->word != nullptr) {
        result.push_back(*cur->word);
        cur->word = nullptr;
    }

    board[r][c] = '#';
    for (int i=0; i<4; ++i) dfs(board, r+dirs[i], c+dirs[i+1], cur);
    board[r][c] = orgChar;
}

vector<string> find_words (vector<vector<char>>& board, vector<string>& words) {
    TrieNode trieNode;
    for (string& word : words) trieNode.addWord(word);

    for (int r=0; r<board.size(); ++r)
        for (int c=0; c<board[0].size(); ++c)
            dfs(board, r, c, &trieNode);
    
    return result;
}



int main() {
    // INPUT :
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};

    // OUTPUT :
    auto result = find_words(board, words);
    cout<<"["; for (auto x : result) cout<<x<<", "; cout<<"\b\b]"<<endl;

    return 0;
}