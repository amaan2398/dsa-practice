/*
@ Creator: Amaan Shaikh
@ Problem_Title: longestSubstrWithoutRepChar
    @ Problem_Statement: Given a string s, find the length of the longest substring without repeating characters.
    @ Data_Structure: Map, 2 pointers
    @ Algorithm: sliding window max
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
@ Approach: Optimized Approach 2
@ Date_Time: July 17, 2022 00:28:16
*/

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = S.size();
    int ptr1 = -1;
    int ptr2 = 0;
    vector<int> position(256,-1);
    int maxLen = 0;
    while(ptr2 < n){
        if(position[S[ptr2]] != -1){
            ptr1 = max(ptr1,position[S[ptr2]]);
        }
        position[S[ptr2]] = ptr2;
        maxLen = max(maxLen, (ptr2-ptr1));
        ptr2++;
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}