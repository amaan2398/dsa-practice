/*
@ Creator: Amaan Shaikh
@ Problem_Title: countSort
    @ Problem_Statement: 
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 22, 2022 07:17:43
*/

#include<bits/stdc++.h>

using namespace std;

void countSort(int* arr, int n){
    int K = INT_MIN;
    for(int i = 0; i < n; i++){
        K = max(arr[i],K);
    }
    K++;
    int counter[K];
    for(int i = 0; i < K; i++){
        counter[i] = 0;
    }

    for(int i = 0; i < n; i++){
        counter[arr[i]]++;
    }

    for(int i = 1; i < K; i++){
        counter[i]+=counter[i-1];
    }
    
    int result[n];
    for(int i = n-1; i >= 0; i--){
        result[--counter[arr[i]]] = arr[i];
    }

    for(int i = 0; i < n; i++){
        arr[i] = result[i];
    }
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    countSort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}