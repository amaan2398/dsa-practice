/*
@ Creator: Amaan Shaikh
@ Problem_Title: wordLadder
    @ Problem_Statement: A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that: Every adjacent pair of words differs by a single letter. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList. sk == endWord Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
    @ Data_Structure: Queue (BFS)
    @ Algorithm: BFS
    @ Level: Hard
    @ URL: https://leetcode.com/problems/word-ladder/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:30:30
*/

#include<bits/stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words;
    bool found = false;
    for(int i = 0; i < wordList.size(); i++){
        if(endWord == wordList[i]){
            found = true;
        }
        words.insert(wordList[i]);
    }
    if(found == false){
        return 0;
    }
    int depth = 0;
    queue<string> q;
    q.push(beginWord);
    depth++;
    int count = q.size();
    while(!q.empty()){
        string w = q.front();
        q.pop();
        count--;
        for(int j = 0; j < w.size();j++){
            string temp = w;
            for(int i = 0;i < 26; i++){
                char ch = ('a'+i);
                temp[j] = ch;
                if(words.find(temp) != words.end()){
                    if(temp == endWord){
                        return ++depth;
                    }
                    q.push(temp);
                    words.erase(temp);
                }
            }
        }
        if(count == 0){
            count = q.size();
            depth++;
        }
    }
    return 0;
}

int main(){
    string a,b;
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    vector<string> arr(n,"");
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << ladderLength(a,b,arr);
    return 0;
}