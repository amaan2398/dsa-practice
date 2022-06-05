/*
@ Creator: Amaan Shaikh
@ Problem_Title: findNumOfOneInBNum
    @Problem_Statement: Write a program to count the number of ones in binary representation of number
    @ Data_Structure: Bit Manipulation
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/set-bits0143/1/
@ Approach: Optimized Approach 1
@ Date_Time: June 05, 2022 22:38:21
*/

#include<bits/stdc++.h>

using namespace std;

int findSetBits(int number){
    if(number==0){
        return 0;
    }
    int nextNumber = (number&(number-1));
    return 1+findSetBits(nextNumber);
}

int main(){
    int number;
    cin >> number;
    cout << findSetBits(number)<<endl;
    return 0;
}