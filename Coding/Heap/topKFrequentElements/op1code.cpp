/*
@ Creator: Amaan Shaikh
@ Problem_Title: topKFrequentElements
    @ Problem_Statement: 
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 29, 2022 08:14:57
*/

#include<bits/stdc++.h>

using namespace std;

struct compare{
    bool  operator()(pair<int,int> &a, pair<int,int> &b){
        if(a.first < b.first){
            return true;
        }
        return false;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> freq;
    int n = nums.size(); //length
    for(int i = 0; i < n; i++){
        freq[nums[i]]++; // if values is not present it's init with 0; 
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    for(auto it: freq){
        pq.push({it.second,it.first});
    }
    vector<int> ans;
    for(int i = 0; i < k; i++){
        pair<int,int> data = pq.top();
        ans.push_back(data.second);
        pq.pop();
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> result = topKFrequent(arr,k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }cout << endl;
    return 0;
}
