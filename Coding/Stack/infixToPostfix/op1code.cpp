/*
@ Creator: Amaan Shaikh
@ Problem_Title: infixToPostfix
    @ Problem_Statement: Given an infix expression in the form of string str. Convert this infix expression to postfix expression.
    @ Data_Structure: Stack 
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
@ Approach: Optimized Approach 1
@ Date_Time: July 27, 2022 02:54:54
*/

#include<bits/stdc++.h>

using namespace std;

int priority(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    return -1;
}
string infixToPostfix(string s) {
    // Your code here
    s.push_back(')');
    int n = s.size();
    string expr;
    stack<char> st;
    st.push('(');
    for(int i = 0;i < n; i++){
        if((priority(s[i]) >= 0)){
            while((!st.empty()) and (priority(s[i]) <= priority(st.top()))){
                expr.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
                while((!st.empty()) and ('(' != st.top())){
                expr.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            expr.push_back(s[i]);
        }
        
    }
    return expr;
}

int main(){
    string S;
    cin >> S;
    cout << infixToPostfix(S);
    return 0;
}