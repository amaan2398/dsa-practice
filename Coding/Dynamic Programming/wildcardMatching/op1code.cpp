/*
@ Creator: Amaan Shaikh
@ Problem_Title: wildcardMatching
    @ Problem_Statement: Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where: '?' Matches any single character. '*' Matches any sequence of characters (including the empty sequence). The matching should cover the entire input string (not partial).
    @ Data_Structure: DP string
    @ Algorithm: Recursion
    @ Level: Hard
    @ URL: https://leetcode.com/problems/wildcard-matching/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:18:06
*/

#include<bits/stdc++.h>

using namespace std;

bool isMatching(int i, int j, string &s, string &p, vector<vector<int>> &dp){
    if(i < 0 and j < 0){
        return true;
    }
    if(i >= 0 and j < 0){
        return false;
    }
    if(i < 0 and j >= 0){
        for(int k = j; k >= 0; k--){
            if(p[k] != '*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(s[i] == p[j] || p[j] == '?'){
        return dp[i][j] = isMatching(i-1,j-1,s,p,dp);
    }
    if(p[j] == '*'){
        return dp[i][j] = (isMatching(i-1,j,s,p,dp)||isMatching(i,j-1,s,p,dp));
    }
    return dp[i][j] = false;
}
bool isMatch(string s, string p) {
    int i = s.size();
    int j = p.size();
    vector<vector<int>> dp(i,vector<int>(j,-1));
    return isMatching(i-1, j-1, s, p,dp);
}

int main(){
    string s,p;
    cin >> s;
    cin >> p;
    cout << isMatch(s,p);
    return 0;
}