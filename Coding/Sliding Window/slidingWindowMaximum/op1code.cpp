/*
@ Creator: Amaan Shaikh
@ Problem_Title: slidingWindowMaximum
    @ Problem_Statement: You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
    @ Data_Structure: Deque
    @ Algorithm: None
    @ Level: Hard
    @ URL: https://leetcode.com/problems/sliding-window-maximum/
@ Approach: Optimized Approach 1
@ Date_Time: June 23, 2022 07:59:22
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> maxWindowK;
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while((!dq.empty()) && (nums[dq.back()] < nums[i])){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    maxWindowK.push_back(nums[dq.front()]);
    for(int i = k; i < n; i++){
        while((!dq.empty()) && (dq.front() < (i-(k-1)))){
            dq.pop_front();
        }
        while((!dq.empty()) && (nums[dq.back()] < nums[i])){
            dq.pop_back();
        }
        dq.push_back(i);
        maxWindowK.push_back(nums[dq.front()]);
    }
    return maxWindowK;
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

