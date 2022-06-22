/*
@ Creator: Amaan Shaikh
@ Problem_Title: quickSort
    @ Problem_Statement: Write a program to sort array of integers using Quick Sort algorithm.
    @ Data_Structure: Array
    @ Algorithm: Merge Sort
    @ Level: Easy
    @ URL: https://www.geeksforgeeks.org/quick-sort/
@ Approach: Optimized Approach 1
@ Date_Time: June 22, 2022 06:30:18
*/

#include<bits/stdc++.h>

using namespace std;

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int* arr, int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j < r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


void quickSort(int* arr, int l, int r){
    if(l<r){
        int piv = partition(arr,l,r);
        
        quickSort(arr,l,piv-1);
        quickSort(arr,piv+1,r);
    }
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}