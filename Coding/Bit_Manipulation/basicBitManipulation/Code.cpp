/*
@ Creator: Amaan Shaikh
@ Problem_Title: basicBitManipulation
    @ Data_Structure: None
    @ Algorithm: None
    @ Level: Easy-Medium 🚧
    @ URL: https://www.geeksforgeeks.org/bitwise-hacks-for-competitive-programming/
@ Approach: Introdution to concepts
@ Date_Time: June 05, 2022 18:05:28
*/

#include<bits/stdc++.h>

using namespace std;

bool getBit(int number, int position){
    bool bit = (number & (1<<position));
    return bit; 
}

int setBit(int number, int position){
    int newNumber = (number | (1<<position));
    return newNumber;
}

int clearBit(int number, int position){
    int mask = ~(1<<position);
    int newNumber = (number & mask);
    return newNumber;
}

int updateBit(int number, int position, bool value){
    if (value == 0){
        return clearBit(number,position);
    }
    return setBit(number,position);
}

int toggleBit(int number, int position){
    bool bit = getBit(number, position);
    if(bit == 0){
        return setBit(number, position);
    }
    return clearBit(number, position);
}

int main(){
    int number = 0, position = 0;
    bool value = 0; 
    cout << "git Bit" << endl;
    cout << "Provide number & position:" << endl;
    cin >> number >> position;
    cout << getBit(number, position) << endl;


    cout << "set Bit" << endl;
    cout << "Provide number & position:" << endl;
    cin >> number >> position;
    cout << setBit(number, position) << endl;


    cout << "clear Bit" << endl;
    cout << "Provide number & position:" << endl;
    cin >> number >> position;
    cout << clearBit(number, position) << endl;


    cout << "update Bit" << endl;
    cout << "Provide number & position  & value:" << endl;
    cin >> number >> position >> value;
    cout << updateBit(number, position, value) << endl;


    cout << "toggle Bit" << endl;
    cout << "Provide number & position:" << endl;
    cin >> number >> position;
    cout << toggleBit(number, position) << endl;
    return 0;
}