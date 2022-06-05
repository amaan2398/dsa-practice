/*
@ Creator: Amaan Shaikh
@ Problem_Title: findUniqueNumberOthNum2
    @ Problem_Statement: Find the element that appears once in an array where every other element appears twice
    @ Data_Structure: Bit Manipulation 
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
@ Approach: Optimized Approach 1
@ Date_Time: June 05, 2022 23:09:24
*/

#include<bits/stdc++.h>

using namespace std;

int findUniqueNumber(int arr[], int n){
    int uniqueNum = arr[0];
    for(int i = 1; i < n; i++){
        uniqueNum = (uniqueNum ^ arr[i]);
    }
    return uniqueNum;
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout << findUniqueNumber(arr,n);
    return 0;
}