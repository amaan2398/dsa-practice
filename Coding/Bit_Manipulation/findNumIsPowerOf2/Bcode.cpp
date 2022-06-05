/*
@ Creator: Amaan Shaikh
@ Problem_Title: findNumIsPowerOf2
    @ Data_Structure: Bit Manipulation
    @ Algorithm: getBit
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
@ Approach: Broad Force
@ Date_Time: June 05, 2022 18:59:49
*/

#include<bits/stdc++.h>

using namespace std;

bool getBit(int number, int position){
    bool bitAtPosition = (number & (1 << position));
    return bitAtPosition;
}

int main(){
    int number=0;
    cin >> number;
    bool isSetBitFound = false;
    bool isMultiSetBitFound = false;
    for(int checkPos = 0; checkPos < 32; checkPos++){
        bool bitAtPos = getBit(number,checkPos);
        if((isSetBitFound) and (bitAtPos == 1)){
            isMultiSetBitFound = true;
            break;
        }
        if(bitAtPos == 1){
            isSetBitFound = true;
        }
    }
    if((isMultiSetBitFound == true) or (isSetBitFound != true)){
        cout << "Number is not a power of 2"<< endl;
    }
    else{
        cout << " Number is a power of 2"<< endl;
    }
    return 0;
}