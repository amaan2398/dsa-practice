/*
@ Creator: Amaan Shaikh
@ Problem_Title: reverseWordsInGivenString
    @ Problem_Statement: Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
@ Approach: Optimized Approach 1
@ Date_Time: July 26, 2022 23:13:00
*/

#include<bits/stdc++.h>

using namespace std;

string reverseWords(string S) 
{ 
    // code here 
    stack<string> st;
    string str;
    for(int i = 0; i < S.size(); i++){
        
        if(S[i]!='.'){
            str.push_back(S[i]);
        }
        else{
            st.push(str);
            str.clear();
        }
    }
    st.push(str);
    string reverseSent;
    while(!st.empty()){
        string word = st.top();
        st.pop();
        reverseSent+=word;
        if(!st.empty()){
            reverseSent.push_back('.');
        }
    }
    return reverseSent;
} 

int main(){
    string S;
    cin >> S;
    cout << reverseWords(S);
    return 0;
}