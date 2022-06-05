/*
@ Creator: Amaan Shaikh
@ Problem_Title: findNumIsPowerOf2
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 05, 2022 18:59:49
*/

#include<bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n){
    if (n==0){
        return false;
    }
    bool bit = (n & (n-1));
    return (bit==0);
}

int main(){
    int number;
    cin>> number;
    cout << isPowerOfTwo(number)<<endl;
    return 0;
}