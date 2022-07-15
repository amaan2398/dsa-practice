/*
@ Creator: Amaan Shaikh
@ Problem_Title: maximumRectangularAreaHistogram
    @ Problem_Statement: Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
@ Approach: Optimized Approach 1
@ Date_Time: July 15, 2022 21:27:03
*/

#include<bits/stdc++.h>

using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<long long> data;
    for(int i = 0; i < n; i++){
        data.push_back(arr[i]);
    }
    data.push_back(0);
    stack<long long> st;
    long long ans = 0;
    for(int i = 0; i <= n; i++){
        while((!st.empty())and (data[st.top()] > data[i])){
            long long pos = st.top();
            long long h = data[pos];
            st.pop();
            if(st.empty()){
                long long v = h*i;
                ans = max(ans, v);
            }
            else{
                long long v = h*((i-st.top())-1);
                ans = max(ans, v);
            }
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << getMaxArea(arr,n)<<endl;
    return 0;
}