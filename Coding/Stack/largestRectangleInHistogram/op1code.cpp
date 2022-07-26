/*
@ Creator: Amaan Shaikh
@ Problem_Title: largestRectangleInHistogram
    @ Problem_Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Hard
    @ URL: https://leetcode.com/problems/largest-rectangle-in-histogram/
@ Approach: Optimized Approach 1
@ Date_Time: July 27, 2022 03:46:39
*/

#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int n = heights.size();
    stack<int> st;
    int ans = 0;
    for(int i = 0;i < n; i++){
        while((!st.empty()) && (heights[st.top()] > heights[i])){
            int pos = st.top();
            st.pop();
            int h = heights[pos];
            if(st.empty()){
                ans = max(ans, (h*i));
            }
            else{
                int ran = st.top();
                ans = max(ans, (h*(i-ran-1)));
            }
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> h(n,0);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    cout << largestRectangleArea(h);
    return 0;
}