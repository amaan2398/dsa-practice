/*
@ Creator: Amaan Shaikh
@ Problem_Title: maxSumSubarray
    @ Problem_Statement: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    @ Data_Structure: Array
    @ Algorithm: Kadane's Algorithm
    @ Level: Easy
    @ URL: https://leetcode.com/problems/maximum-subarray/
@ Approach: Optimized Approach 1
@ Date_Time: June 07, 2022 01:18:12
*/

#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN; // Initialized with Min value of Int, 
    //For case where all values of array is -ve then to capture -ve values of array 
    int sum = 0;
    int lenNums = nums.size();
    // Kadane's Algorithm
    for(int i = 0; i < lenNums; i++){
        sum += nums[i];
        maxSum = max(sum,maxSum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << maxSubArray(nums)<< endl;
    return 0;
}