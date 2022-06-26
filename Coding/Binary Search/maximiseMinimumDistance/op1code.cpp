/*
@ Creator: Amaan Shaikh
@ Problem_Title: maximiseMinimumDistance
    @ Problem_Statement: Given array with n elements that represents n positions along a straight line. Find K elements such that the minimum distance between any 2 elements is the maximum possible.
    @ Data_Structure: Array
    @ Algorithm: Binary Seach
    @ Level: Medium
    @ URL: https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/
@ Approach: Optimized Approach 1
@ Date_Time: June 26, 2022 07:23:11
*/

#include<bits/stdc++.h>

using namespace std;

bool isFeasible(vector<int> &arr, int n, int k, int dis){
    int ele = arr[0];
    int count = 1;
    for(int i = 1; i < n; i++){
        if((arr[i]-ele) >= dis){
            count++;
            ele = arr[i];
            if(count == k){
                return true;
            }
        }
    }
    if(count >= k){
        return true;
    }
    return false;
}

int getDistance(vector<int> &arr, int n, int k){
    sort(arr.begin(),arr.end());
    int left = 1, right = arr[n-1];
    int ans = -1;
    while(left < right){
        int mid = (left+right)/2;
        if(isFeasible(arr,n,k,mid)){
            ans = max(ans,mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return ans;
}

int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << getDistance(arr, n, k) << endl;
    return 0;
}