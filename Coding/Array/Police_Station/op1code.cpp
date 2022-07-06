/*
@ Creator: Amaan Shaikh
@ Problem_Title: Police_Station
    @ Problem_Statement: 
    @ Data_Structure: Array
    @ Algorithm: Find top max 2 and bottom min 2
    @ Level: Easy->Medium
    @ URL: https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#
@ Approach: Optimized Approach 1
@ Date_Time: July 06, 2022 23:55:12
*/

#include<bits/stdc++.h>

using namespace std;

int solve(int N, int a, vector<int> x) {
    // code here
    if(N == 2){
        return abs(x[0]-a)+abs(x[1]-a);
    }
    for(int i = 0; i < N; i++){
        x[i] = abs(x[i]-a);
        // cout << x[i] << " ";
    }
    // cout <<endl;
    int ele1 = max(x[0],x[1]);
    int ele2 = min(x[0],x[1]);
    int ele3 = max(x[0],x[1]);
    int ele4 = min(x[0],x[1]);
    for(int i = 2; i < N; i++){
        if(ele1 <= x[i]){
            ele2 = max(ele1,ele2);
            ele1 = x[i];
        }
        else if( ele2 < x[i]){
            ele2 = x[i];
        }
        if(ele4 >= x[i]){
            ele3 = min(ele4,ele3);
            ele4 = x[i];
        }
        else if( ele3 > x[i]){
            ele3 = x[i];
        }
    }
    // cout << ele1 << " " << ele2 << " " << ele3 << " " << ele4 << endl;
    return max(max((ele1+ele2),(ele3+ele4)),(ele1+ele4));
}

int main(){
    int n = 0,a = 0;
    cin >> n >> a;
    vector<int> arr(n,-1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(n,a,arr);
    return 0;
}