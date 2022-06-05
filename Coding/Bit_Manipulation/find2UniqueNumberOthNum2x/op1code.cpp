/*
@ Creator: Amaan Shaikh
@ Problem_Title: find2UniqueNumberOthNum2x
    @ Problem_Statement: Find the 2 unique elements that appears only once in an array where every other element appears twice
    @ Data_Structure: Bit Manipulation
    @ Algorithm: none
    @ Level: Medium-Hard
    @ URL: https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
@ Approach: Optimized Approach 1
@ Date_Time: June 05, 2022 23:19:45
*/

#include<bits/stdc++.h>

using namespace std;

bool getBit(int num, int pos){
    bool bit = (num & (1<<pos));
    return bit;
}

int findRightMostSetBit(int num){
    for(int i = 0; i < 32; i++){
        if(getBit(num,i)){
            return i;
        }
    }
    return -1;
}

pair<int,int> find2UniqueNumbers(int arr[], int n){
    // Remove all duplicates from intrest visition
    int uniqueNums = 0;
    for(int i = 0; i < n; i++){
        uniqueNums = (uniqueNums^arr[i]);
    }

    // Now uniqueNums is having value of 2 unique number XOR result.
    // We will find right most set bit in uniqueNums
    // Then find XOR of all number which having same position set bit.
    int posSetBit = findRightMostSetBit(uniqueNums);
    if(posSetBit != -1){
        int uniqueNum1 = 0;
        for(int i = 0; i < n; i++){
            if(getBit(arr[i],posSetBit)){
                uniqueNum1 = (uniqueNum1^arr[i]);
            }
        }
        int uniqueNum2 = uniqueNums^uniqueNum1;
        return make_pair(uniqueNum1,uniqueNum2);
    }
    return make_pair(-1,-1);
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pair<int, int> numbers = find2UniqueNumbers(arr,n);
    cout << numbers.first << " " <<numbers.second<< endl;
    return 0;
}