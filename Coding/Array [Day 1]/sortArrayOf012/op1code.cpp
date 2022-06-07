/*
@ Creator: Amaan Shaikh
@ Problem_Title: sortArrayOf012
    @ Problem_Statement: You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
    @ Data_Structure: Array
    @ Algorithm: DNF Sort algo.
    @ Level: Easy
    @ URL: https://leetcode.com/problems/sort-colors/
@ Approach: Optimized Approach 1
@ Date_Time: June 08, 2022 01:14:33
*/

#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums){
    int numsLen = nums.size();
    int ptrZero = 0; // From start to this pointer zeros present.
    int ptrTwo = numsLen-1;
    int ptrCurr = 0;
    
    while(ptrCurr<=ptrTwo){
        if(nums[ptrCurr] == 0){
            swap(nums[ptrZero],nums[ptrCurr]);
            ptrZero++;
            ptrCurr = max(ptrZero, ptrCurr);
        }
        else if( nums[ptrCurr] == 2){
            swap(nums[ptrTwo],nums[ptrCurr]);
            ptrTwo--;
        }
        else{
            ptrCurr++;
        }
    }
}

int main(){
    int n = 0; 
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sortColors(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}