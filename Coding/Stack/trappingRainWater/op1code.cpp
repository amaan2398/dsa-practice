/*
@ Creator: Amaan Shaikh
@ Problem_Title: trappingRainWater
    @ Problem_Statement: Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
    @ Data_Structure: Stack
    @ Algorithm: 
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
@ Approach: Optimized Approach 1
@ Date_Time: July 15, 2022 21:58:00
*/

#include<bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n){
    stack<int> st;
    long long ans = 0;
    long long pos, h;
    for(int i = 0; i < n; i++){
        while((!st.empty()) and (arr[st.top()] < arr[i])){
            pos = st.top();
            st.pop();
            h = arr[pos];
            if(st.empty()){
                continue;
            }
            long long npos = st.top();
            long long nh = arr[npos];
            long long minH = min((long long)arr[i],nh);
            ans += ((minH-h)*((i-npos)-1));
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n = 0;
    cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << trappingWater(arr,n) << endl;
    return 0;
}