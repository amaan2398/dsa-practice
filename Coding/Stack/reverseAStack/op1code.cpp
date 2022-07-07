/*
@ Creator: Amaan Shaikh
@ Problem_Title: reverseAStack
    @ Problem_Statement: You are given a stack St. You have to reverse the stack using recursion.
    @ Data_Structure: Stack
    @ Algorithm: Recursion
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/reverse-a-stack/1/#
@ Approach: Optimized Approach 1
@ Date_Time: July 07, 2022 23:29:57
*/

#include<bits/stdc++.h>

using namespace std;

void rev(stack<int> &St, vector<int> &ans){
    if(St.empty()){
        return;
    }
    int ele = St.top();
    St.pop();
    ans.push_back(ele);
    rev(St,ans);
}
vector<int> Reverse(stack<int> St){
    vector<int> ans;
    rev(St,ans);
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    stack<int> st;
    for(int i = 0;i < n; i++){
        int t;
        cin >> t;
        st.push(t);
    }
    vector<int> ans = Reverse(st);
    for(int i: ans){
        cout << i << " ";
    }cout << endl;
    return 0;
}