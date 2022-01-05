// PROBLEM: Word Ladder
// https://leetcode.com/problems/word-ladder/
// https://www.interviewbit.com/problems/word-ladder-i/


#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

// SOLUTION
int ladder_length (string begin_word, string end_word, vector<string>& word_list) {
    unordered_set<string> dict(word_list.begin(), word_list.end());
    queue<string> todo;
    todo.push(begin_word);
    int ladder = 1;
    
    while (!todo.empty()) {
        int n = todo.size();
        
        for (int i=0; i<n; i++) {
            string word = todo.front();
            todo.pop();
            if (word == end_word) return ladder;

            dict.erase(word);
            for (int j=0; j<word.size(); j++) {
                char c = word[j];

                for (int k=0; k<26; k++) {
                    word[j] = 'a' + k;
                    if (dict.find(word) != dict.end())
                        todo.push(word);
                }

                word[j] = c;
            }
        }

        ladder++;
    }
    
    return 0;
}


int main() {
    // INPUT :
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list = {"hot","dot","dog","lot","log","cog"};

    // OUTPUT :
    cout<<ladder_length(begin_word, end_word, word_list)<<endl;

    return 0;
}