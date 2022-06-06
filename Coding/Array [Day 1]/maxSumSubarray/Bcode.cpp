/*
@ Creator: Amaan Shaikh
@ Problem_Title: maxSumSubarray
    @ Problem_Statement: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/maximum-subarray/
@ Approach: Broad Force
@ Date_Time: June 07, 2022 01:18:12
*/

#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    int lenNums = nums.size();
    for(int i = 0; i < lenNums; i++){
        for(int j = 0; j < lenNums; j++){
            sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
                maxSum = max(sum,maxSum);
            }
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