/*
@ Creator: Amaan Shaikh
@ Problem_Title: trappingRainWater
    @ Problem_Statement: Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
    @ Data_Structure: Array //[~short~ DP]
    @ Algorithm: Prefix Sum Postfix Sum min difference with original array.
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
@ Approach: Broad Force
@ Date_Time: July 15, 2022 21:58:00
*/

#include<bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n){
    long long ans = 0;
    int larr[n],rarr[n];
    larr[0] = arr[0];
    rarr[n-1] = arr[n-1];
    for(int i = 1; i < n; i++){
        larr[i] = max(larr[i-1],arr[i]);
    }
    for(int i = n-2; i >= 0; i--){
        rarr[i] = max(rarr[i+1],arr[i]);
    }
    for(int i = 1; i < n-1; i++){
        larr[i] = min(larr[i],rarr[i]);
    }
    for(int i = 1; i < n-1; i++){
        ans += (long long)(larr[i]-arr[i]);
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