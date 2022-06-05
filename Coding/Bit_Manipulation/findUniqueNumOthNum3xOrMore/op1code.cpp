/*
@ Creator: Amaan Shaikh
@ Problem_Title: findUniqueNumOthNum3xOrMore
    @ Problem_Statement: Find the unique element that appears only once in an array where every other element appears 3 time.
    @ Data_Structure: Bit Manipulation
    @ Algorithm: None
    @ Level: Hard
    @ URL: https://www.geeksforgeeks.org/find-the-element-that-appears-once/
@ Approach: Optimized Approach 1
@ Date_Time: June 05, 2022 23:55:24
*/

#include<bits/stdc++.h>

using namespace std;

bool getBit(int n, int pos){
    bool bit = (n & (1<<pos));
    return bit;
}

int findUniqueNum(int arr[], int n){
    int uniqueNum = 0;
    int counter[32];
    for(int i = 0; i < 32; i++){
        counter[i]=0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 32; j++){
            counter[j]+=getBit(arr[i],j);
        }
    }
    for(int i = 0; i < 32; i++){
        if((counter[i]%3) == 1){
            uniqueNum = (uniqueNum | (1<<i));
        }
    }
    return uniqueNum;
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << findUniqueNum(arr,n);

    return 0;
}