/*
@ Creator: Amaan Shaikh
@ Problem_Title: slidingWindowMaximum
    @ Problem_Statement: You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Hard
    @ URL: https://leetcode.com/problems/sliding-window-maximum/
@ Approach: Broad Force
@ Date_Time: June 23, 2022 07:59:22
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();
    for(int i = 0; i < (n-(k-1)); i++){
        int maxV = INT_MIN;
        for(int j = 0; j < k; j++){
            maxV = max(maxV,nums[i+j]);
        }
        result.push_back(maxV);
    }
    return result;
}


int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0; i < n;i++){
        cin >> nums[i];
    }

    vector<int> result = maxSlidingWindow(nums,k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }cout << endl;
    
    return 0;
}