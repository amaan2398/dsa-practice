/*
@ Creator: Amaan Shaikh
@ Problem_Title: geeklandColosseum
    @ Problem_Statement: 
    @ Data_Structure: Heap/slidding window
    @ Algorithm: Suffix and prefix sum
    @ Level: Medium -> Hard
    @ URL: https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#
@ Approach: Optimized Approach 1
@ Date_Time: July 06, 2022 23:44:23
*/

#include<bits/stdc++.h>

using namespace std;

long long colosseum(int N,vector<int> A) {
        int len = A.size();
        long long maxval = INT_MIN;
        vector<long long> prefsum(len,-1);
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum = 0;
        for(int i = 0; i < N; i++){
            pq.push(A[i]);
            sum += A[i];
        }
        prefsum[N-1] = (sum);
        for(int i = N; i < (len-N); i++){
            if(pq.top() <= A[i]){
                sum-=pq.top();
                pq.pop();
                sum+=A[i];
                pq.push(A[i]);
            }
            prefsum[i] = (sum);
        }
        priority_queue<int,vector<int>> pqmax;
        sum = 0;
        vector<long long> suffsum(len,-1);
        for(int i = len-1; i >= len-N; i--){
            pqmax.push(A[i]);
            sum += A[i];
        }
        suffsum[(len-N)] = sum;
        for(int i = (len-N-1); i >= N; i--){
            if(pqmax.top() > A[i]){
                sum-=pqmax.top();
                pqmax.pop();
                sum+=A[i];
                pqmax.push(A[i]);
            }
            suffsum[i] = (sum);
        }
        for(int i = N-1; i < len-N; i++){
            maxval = max(maxval,(prefsum[i]-suffsum[i+1]));
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