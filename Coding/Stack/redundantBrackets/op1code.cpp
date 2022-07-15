/*
@ Creator: Amaan Shaikh
@ Problem_Title: redundantBrackets
    @ Problem_Statement: Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters. Note : A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473
@ Approach: Optimized Approach 1
@ Date_Time: July 15, 2022 22:45:17
*/

#include<bits/stdc++.h>

using namespace std;

bool checkSym(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    int n = s.size();
    for(int i = 0;i < n; i++){
        if(s[i] == '(' || checkSym(s[i])){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            bool flag = false;
            while((!st.empty()) and checkSym(st.top())){
                flag = true;
                st.pop();
            }
            if((flag == false) || (st.empty())){
                return true;
            }
            if(st.top() == '('){
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    int n = 0;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << (findRedundantBrackets(s)?"Yes":"No") << endl;
    }
    return 0;
}