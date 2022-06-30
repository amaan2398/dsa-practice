/*
@ Creator: Amaan Shaikh
@ Problem_Title: arithmeticSubarrays
    @ Problem_Statement: You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed. Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
    @ Data_Structure: Priority Queue/ Heap
    @ Algorithm: Sorting
    @ Level: Medium
    @ URL: https://leetcode.com/problems/arithmetic-subarrays/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:36:54
*/

#include<bits/stdc++.h>

using namespace std;

bool isGood(priority_queue<int,vector<int>,greater<int>> &pq){
    int n = pq.size();
    if(n < 2){
        return false;
    }
    int num1 = pq.top();
    pq.pop();
    int num2 = pq.top();
    pq.pop();
    int diff = num2-num1;
    while(!pq.empty()){
        num1 = num2;
        num2 = pq.top();
        pq.pop();
        if(diff != (num2-num1)){
            return false;
        }
    }
    return true;
    
}
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int q = l.size();
    vector<bool> ans;
    for(int i = 0; i < q; i++){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j = l[i]; j <= r[i]; j++){
            pq.push(nums[j]);
        }
        ans.push_back(isGood(pq));
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> l(m,0),r(m,0);
    for(int i = 0; i < m; i++){
        cin >> l[i];
    }
    for(int i = 0; i < m; i++){
        cin >> r[i];
    }
    vector<bool> ans = checkArithmeticSubarrays(arr, l, r);
    for(int i = 0;i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}