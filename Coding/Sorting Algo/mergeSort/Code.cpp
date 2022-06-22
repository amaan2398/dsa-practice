/*
@ Creator: Amaan Shaikh
@ Problem_Title: mergeSort
    @ Problem_Statement: Write a program to sort array of integers using Merge Sort algorithm.
    @ Data_Structure: Array
    @ Algorithm: Merge Sort
    @ Level: Easy
    @ URL: https://www.geeksforgeeks.org/merge-sort/
@ Approach: Optimized Approach 1
@ Date_Time: June 22, 2022 06:00:51
*/

#include<bits/stdc++.h>

using namespace std;

void merge(int* arr, int l, int mid, int r){
    int lenA = (mid-l)+1;
    int lenB = (r-(mid+1))+1;
    
    int arrA[lenA], arrB[lenB];
    for(int i = l; i<=mid; i++){
        arrA[i-l] = arr[i]; 
    }
    for(int j = mid+1; j<=r; j++){
        arrB[j-(mid+1)] = arr[j]; 
    }

    int ptr1 = 0, ptr2 = 0, k = l;
    while((ptr1 < lenA) && (ptr2 < lenB)){
        if(arrA[ptr1]<arrB[ptr2]){
            arr[k++] = arrA[ptr1++];
        }
        else{
            arr[k++] = arrB[ptr2++];
        }
    }

    while(ptr1 < lenA){
        arr[k++] = arrA[ptr1++];
    }

    while(ptr2 < lenB){
        arr[k++] = arrB[ptr2++];
    }
}

void mergeSort(int* arr,int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}