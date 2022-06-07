/*
@ Creator: Amaan Shaikh
@ Problem_Title: sortArrayOf012
    @ Problem_Statement: You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.
    @ Data_Structure: Array
    @ Algorithm: Sort Algo [Like Merge Sort, Quick Sort]
    @ Level: Easy
    @ URL: https://leetcode.com/problems/sort-colors/
@ Approach: Broad Force
@ Date_Time: June 08, 2022 01:14:33
*/

#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums){
    sort(nums.begin(), nums.end()); //O(n*log(n)) this can be improved by DNF sort algo.
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