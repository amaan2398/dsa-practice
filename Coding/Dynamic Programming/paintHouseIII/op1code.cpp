/*
@ Creator: Amaan Shaikh
@ Problem_Title: paintHouseIII
    @ Problem_Statement: There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again. A neighborhood is a maximal group of continuous houses that are painted with the same color. Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.
    @ Data_Structure: None
    @ Algorithm: None
    @ Level: Hard
    @ URL: https://leetcode.com/problems/paint-house-iii/
@ Approach: Optimized Approach 1
@ Date_Time: July 08, 2022 22:51:22
*/

#include<bits/stdc++.h>

using namespace std;

int dp[102][102][22];
int helper(vector<int>& houses, vector<vector<int>>& cost, int curr, int totalCost, int t,int target, int color){
    if((target < t)){
        return INT_MAX/2;
    }
    if(curr == houses.size()){
        if(target == t){
            return 0;
        }
        return INT_MAX/2;
    }

    if(dp[curr][t][color] != -1){
        return dp[curr][t][color];
    }
    int ans = INT_MAX/2;
    if(houses[curr] == 0){
        for(int i = 0; i < cost[curr].size(); i++){
            ans = min(ans,cost[curr][i]+helper(houses,cost,curr+1,totalCost,(color == i+1)?t:t+1,target, i+1));
        }
    }
    else{
        ans = min(ans,helper(houses,cost,curr+1,totalCost,(color == houses[curr])?t:t+1,target, houses[curr]));
    }
    dp[curr][t][color] = ans;
    return ans;
}
int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            for(int k = 0; k < 22; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = INT_MAX/2;
    ans = min(ans,helper(houses,cost,0,0,0,target,0));
    if(ans == INT_MAX/2){
        ans = -1;
    }
    return ans;
}

int main(){
    int m, n, t;
    cin >> m >> n >> t;
    vector<int> h(m,0);
    for(int i = 0; i < m; i++){
        cin >> h[i];
    }

    vector<vector<int>> c(m,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    cout << minCost(h,c,m,n,t);
    return 0;
}