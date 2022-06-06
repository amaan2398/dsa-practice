/*
@ Creator: Amaan Shaikh
@ Problem_Title: nextPermutation
    @ Problem_Statement: The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://leetcode.com/problems/next-permutation/
@ Approach: Optimized Approach 1
@ Date_Time: June 07, 2022 01:00:43
*/

#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int lenNumsArray = nums.size();
    int ptrDecOrd = lenNumsArray-1;
    for(int i = lenNumsArray-1; i >= 0; i--){
        if(nums[ptrDecOrd]<= nums[i]){
            ptrDecOrd = i;
        }
        else{
            break;
        }
    }
    int ptrIntrest = ptrDecOrd-1;
    if(ptrIntrest >= 0){
        for(int i = lenNumsArray-1; i >= max(ptrDecOrd,0); i--){
            if(nums[ptrIntrest]< nums[i]){
                swap(nums[ptrIntrest],nums[i]);
                break;
            }
        }
    }
    sort(nums.begin()+max(ptrDecOrd,0),nums.end());
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    nextPermutation(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }cout << endl;
    return 0;
}