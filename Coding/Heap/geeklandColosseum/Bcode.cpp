/*
@ Creator: Amaan Shaikh
@ Problem_Title: geeklandColosseum
    @ Problem_Statement: 
    @ Data_Structure: Heap
    @ Algorithm: None
    @ Level: Medium -> Hard
    @ URL: https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#
@ Approach: Broad Force
@ Date_Time: July 06, 2022 23:44:23
*/

#include<bits/stdc++.h>

using namespace std;

long long colosseum(int N,vector<int> A) {
    int len = A.size();
    
    long long maxval = INT_MIN;
    for(int part = N; part <= (len-N); part++){
        priority_queue<int,vector<int>> pqmax;
        priority_queue<int,vector<int>,greater<int>> pqmin;
        for(int i = 0; i < part; i++){
            pqmax.push(A[i]);
        }
        
        for(int i = part; i < len; i++){
            pqmin.push(A[i]);
        }
        long long s1 = 0;
        long long s2 = 0;
        for(int i = 0; i < N; i++){
            s1+= pqmax.top();
            pqmax.pop();
            s2+= pqmin.top();
            pqmin.pop();
        }
        // cout << s1 << " " << s2 << " "<<(s1-s2) << endl;
        maxval = max(maxval,(s1-s2));
    }
    return maxval;
}

int main(){
    int  n, a;
    cin >>n >> a;
    vector<int> arr(n,-1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << colosseum(a,arr);
    return 0;
}