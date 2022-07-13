/*
@ Creator: Amaan Shaikh
@ Problem_Title: validExpression
    @ Problem_Statement: Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'. The task is to verify the validity of the arrangement. Note: Ignore the precedence of brackets.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Easy-Medium
    @ URL: https://practice.geeksforgeeks.org/problems/valid-expression1025/1/#
@ Approach: Optimized Approach 1
@ Date_Time: July 13, 2022 23:14:46
*/

#include<bits/stdc++.h>

using namespace std;

bool isOpeningOprater(char ch){
    return ((ch =='(') || (ch == '{') || (ch == '['));
}

bool valid(string s)
{
    // code here
    stack<char> st;
    int n = s.size();
    unordered_map<char,char> mp;
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    for(int i = 0; i < n; i++){
        if(isOpeningOprater(s[i])){
            st.push(s[i]);
        }
        else{
            if(st.empty() || (mp[st.top()] != s[i])){
                return false;
            }
            st.pop();
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout << valid(s) << endl;
    return 0;
}