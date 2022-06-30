/*
@ Creator: Amaan Shaikh
@ Problem_Title: maxNumOfCoinsYouCanGet
    @ Problem_Statement: Given an array of integers piles where piles[i] is the number of coins in the ith pile. Return the maximum number of coins that you can have.
    @ Data_Structure: Array
    @ Algorithm: Sorting
    @ Level: Medium
    @ URL: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:06:30
*/

#include<bits/stdc++.h>

using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(),piles.end());
    int fast = piles.size()-1;
    int slow = 0;
    int count = 0;
    while(fast > slow){
        count += piles[fast-1];
        fast-=2;
        slow++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maxCoins(arr);
    return 0;
}