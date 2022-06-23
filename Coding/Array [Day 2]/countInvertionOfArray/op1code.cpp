/*
@ Creator: Amaan Shaikh
@ Problem_Title: countInvertionOfArray
    @ Problem_Statement: For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist. An inversion is defined for a pair of integers in the array/list when the following two conditions are met. A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when: 1. 'ARR[i] > 'ARR[j]' 2. 'i' < 'j' Where 'i' and 'j' denote the indices ranging from [0, 'N').
    @ Data_Structure: Array 
    @ Algorithm: Merge Sort
    @ Level: Medium
    @ URL: https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
@ Approach: Optimized Approach 1
@ Date_Time: June 23, 2022 06:55:57
*/

#include<bits/stdc++.h>

using namespace std;

long long merge(long long *arr, int l, int mid, int r){
    int lenA = ((mid+1)-l);
    int lenB = ((r+1) - (mid+1));
    long long A[lenA], B[lenB];
    for(int i = 0; i < lenA; i++){
        A[i] = arr[l+i];
    }
    
    for(int i = 0; i < lenB; i++){
        B[i] = arr[(mid+1)+i];
    }
    
    long long count = 0;
    int ptr1 = 0, ptr2 = 0, k = l;
    while((ptr1 < lenA) && (ptr2 < lenB)){
        if(A[ptr1] <= B[ptr2]){
            arr[k++] = A[ptr1++];
        }
        else{
            count += (lenA-ptr1);
            arr[k++] = B[ptr2++];
        }
    }
    while(ptr1 < lenA){
        arr[k++] = A[ptr1++];
    }
    
    while(ptr2 < lenB){
        arr[k++] = B[ptr2++];
    }
    return count;
}

long long mergeSort(long long *arr, int l, int r){
    long long count = 0;
    if(l < r){
        int mid = (l+r)/2;
        count += mergeSort(arr,l,mid);
        count += mergeSort(arr,mid+1,r);
        count += merge(arr, l, mid, r);
    }
    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long count = mergeSort(arr, 0, n-1);
    return count;
}


int main(){
    int n = 0;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getInversions(arr,n) << endl;
    return 0;
}