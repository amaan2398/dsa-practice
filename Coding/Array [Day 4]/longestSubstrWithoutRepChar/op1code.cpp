/*
@ Creator: Amaan Shaikh
@ Problem_Title: longestSubstrWithoutRepChar
    @ Problem_Statement: Given a string s, find the length of the longest substring without repeating characters.
    @ Data_Structure: Map, 2 pointers
    @ Algorithm: sliding window max
    @ Level: Medium
    @ URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
@ Approach: Optimized Approach 1
@ Date_Time: June 25, 2022 01:04:22
*/

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    map<char,int> apha;
    for(int i = 0; i < n; i++){
        apha[s[i]] = -1;
    }
    int start = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        start = max(start, apha[s[i]]);
        ans = max(ans, (i-start));
        apha[s[i]] = i;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}