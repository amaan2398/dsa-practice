/*
@ Creator: Amaan Shaikh
@ Problem_Title: evaluationOfPostfixExpression
    @ Problem_Statement: Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
    @ Data_Structure: Stack 
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
@ Approach: Optimized Approach 1
@ Date_Time: July 27, 2022 01:47:14
*/

#include<bits/stdc++.h>

using namespace std;

int evaluatePostfix(string S)
{
    // Your code here
    stack<int> st;
    int op1,op2;
    int n = S.size();
    for(int i = 0;i < n; i++){
        switch(S[i]){
            case '*': 
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1*op2);
                break;
            case '/': 
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1/op2);
                break;
            case '+':
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1+op2);
                break;
            case '-':
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                st.push(op1-op2);
                break;
            default:
                st.push(S[i]-'0');
        }
    }
    return st.top();
}

int main(){
    string S;
    cin >> S;
    cout << evaluatePostfix(S);
    return 0;
}