/*
@ Creator: Amaan Shaikh
@ Problem_Title: maxConsecutiveOnes
    @ Problem_Statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
    @ Data_Structure: Array
    @ Algorithm: 2 pointers
    @ Level: Medium
    @ URL: https://leetcode.com/problems/max-consecutive-ones-iii/
@ Approach: Optimized Approach 1
@ Date_Time: June 24, 2022 23:35:37
*/

#include<bits/stdc++.h>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int countZero = 0;
    int ptrs = 0;
    int ptre = 0;
    int maxLen = 0;
    while(ptre < nums.size()){
        if(nums[ptre] == 1){
            ptre++;
        }
        else if(countZero < k){
            countZero++;
            ptre++;
        }
        else{
            do{
                ptrs++;
            }while(nums[ptrs-1] == 1);
            countZero--;
        }
        maxLen = max(maxLen, (ptre-ptrs));
    }
    return maxLen;
}

int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin>> nums[i];
    }
    cout << longestOnes(nums, k);
    return 0;
}

