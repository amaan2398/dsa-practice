/*
@ Creator: Amaan Shaikh
@ Problem_Title: arithmeticExpressionEvaluation
    @ Problem_Statement: You are given a string ‘expression’ consists of characters ‘+’, ‘-’, ‘*’, ‘/’, ‘(‘, ‘)’ and ‘0’ to ‘9’, that represents an Arithmetic Expression in Infix Notation. Your task is to evaluate this Arithmetic Expression.
    @ Data_Structure: Stack
    @ Algorithm: Infix to Postfix convertion + Postfix evaluation
    @ Level: Medium - Head
    @ URL: https://www.codingninjas.com/codestudio/problems/
@ Approach: Optimized Approach 1
@ Date_Time: July 13, 2022 21:56:28
*/

#include<bits/stdc++.h>

using namespace std;

int operaterPre(char op){
    if((op == '+') || (op == '-')){
        return 1;
    }
    if((op == '*') || (op == '/')){
        return 2;
    }
   return 0;
}

bool opraterPrefFilter(char oprater1, char oprater2){
    return (operaterPre(oprater1) >= operaterPre(oprater2));
}

string infixToPostfixExpression(string &expression, int n){
    string postfixExpression;
    stack<char> st;
    postfixExpression.push_back(' ');
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(expression[i] >= '0' && expression[i]<='9'){
            while(expression[i] >= '0' && expression[i]<='9'){
                postfixExpression.push_back(expression[i++]);
            }
            postfixExpression.push_back(' ');
            i--;
            continue;
        }
        else{
            if(expression[i] == '('){
                st.push(expression[i]);
            }
            else if(expression[i] == ')'){
                while((!st.empty()) && (st.top() != '(')){
                    postfixExpression.push_back(st.top());
                    postfixExpression.push_back(' ');
                    st.pop();
                }
                st.pop();
            }
            else{
                while((!st.empty()) && (opraterPrefFilter(st.top(),expression[i]))){
                    postfixExpression.push_back(st.top());
                    postfixExpression.push_back(' ');
                    st.pop();
                }
                st.push(expression[i]);
            }
        }
    }
    return postfixExpression;
}

pair<int,int> evalInt(string &st, int len, int i){
    int val = 0;
    while((i < len) && ((st[i] >= '0') && (st[i] <= '9'))){
        val*=10;
        val += (st[i]-'0');
        i++;
    }
    return make_pair(val,i);
}

int postfixExpressionEvaluate(string &postfixExpression){
    int op1,op2;
    int m = postfixExpression.size();
    stack<int> st;
    for(int i = 0; i < m; i++){
        if((postfixExpression[i] >= '0') && (postfixExpression[i] <= '9')){
            pair<int,int> dataValIdx = evalInt(postfixExpression,postfixExpression.size(),i);
            st.push(dataValIdx.first);
            i = dataValIdx.second;
            continue;
        }
        if(postfixExpression[i] != ' '){
            op2 = st.top();st.pop();
            op1 = st.top();st.pop();
            switch(postfixExpression[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push((op1-op2));
                    break;
                case '/':
                    st.push(((int)floor((double)(op1/op2))));
                    break;
                case '*':
                    st.push((op1*op2));
                    break;
            }
        }
    }
    return st.top();
}

int evaluateArithmeticExpression(string &expression) 
{
    // Write your code here
    int n = expression.size();
    string postfixExpression = infixToPostfixExpression(expression,n);
    int ans = postfixExpressionEvaluate(postfixExpression);
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << evaluateArithmeticExpression(s) << endl;
    }
    return 0;
}