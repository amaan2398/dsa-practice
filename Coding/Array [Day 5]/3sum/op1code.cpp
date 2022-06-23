/*
@ Creator: Amaan Shaikh
@ Problem_Title: 3sum
    @ Problem_Statement: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == Z. Notice that the solution set must not contain duplicate triplets.
    @ Data_Structure: Array
    @ Algorithm: Two pointer
    @ Level: Medium
    @ URL: https://leetcode.com/problems/3sum/; https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028
@ Approach: Optimized Approach 1
@ Date_Time: June 23, 2022 09:02:15
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	sort(nums.begin(),nums.end());
    
    vector<vector<int>> ans;
    for(int i = 0; i < n;i++){
        if((i > 0) && (nums[i] == nums[i-1])){
            continue;
        }
        int low = i+1;
        int high = n-1;
        while(low < high){
            int sum = nums[i]+nums[low]+nums[high];
            if(sum == K){
                ans.push_back({nums[i],nums[low],nums[high]});
                low++;
                while((low < n) && (nums[low] == nums[low-1])){
                    low++;
                }
            }
            else if(sum < K){
                low++;
            }
            else{
                high--;
            }
        }
    }
    
    return ans;
}

int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> result = findTriplets(nums,n,k);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }cout << endl;
    }
    return 0;
}