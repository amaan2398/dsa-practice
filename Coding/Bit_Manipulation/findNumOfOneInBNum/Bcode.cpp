/*
@ Creator: Amaan Shaikh
@ Problem_Title: findNumOfOneInBNum
    @Problem_Statement: Write a program to count the number of ones in binary representation of number
    @ Data_Structure: Bit Manipulation
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/set-bits0143/1/
@ Approach: Broad Force
@ Date_Time: June 05, 2022 22:38:21
*/

#include<bits/stdc++.h>

using namespace std;

bool getBit(int number, int position){
    return ((number & (1<<position))!=0);
}

int findSetBits(int number){
    int countBits=0;
    for(int pos= 0; pos < 32; pos++){
        countBits+=getBit(number,pos);
    }
    return countBits;
}

int main(){
    int number = 0;
    cin >> number;
    cout << findSetBits(number);
    return 0;
}