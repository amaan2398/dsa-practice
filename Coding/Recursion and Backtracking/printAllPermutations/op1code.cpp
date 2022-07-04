/*
@ Creator: Amaan Shaikh
@ Problem_Title: printAllPermutations
    @ Problem_Statement: Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
    @ Data_Structure: None
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://leetcode.com/problems/permutations/
@ Approach: Optimized Approach 1
@ Date_Time: July 04, 2022 22:15:51
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
void getAllPermute(vector<int>& nums, int idx){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = idx; i < nums.size(); i++){
        swap(nums[idx],nums[i]);
        getAllPermute(nums,idx+1);
        swap(nums[idx],nums[i]);
    }
    return;
}
vector<vector<int>> permute(vector<int>& nums) {
    // vector<vector<int>> ans;
    getAllPermute(nums,0);
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> ans = permute(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
    return 0;
}