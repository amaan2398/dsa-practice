/*
@ Creator: Amaan Shaikh
@ Problem_Title: mergeIntervals
    @ Problem_Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
    @ Data_Structure: 2D Array [sort and interate O(N*logN)+O(N)]
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://leetcode.com/problems/merge-intervals/
@ Approach: Optimized Approach 1
@ Date_Time: June 09, 2022 05:13:22
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(),intervals.end());
    vector<int> ans = intervals[0];
    int pos = 0;
    while(pos < intervals.size()){
        if(ans[1] >= intervals[pos][0]){
            ans[1] = max(ans[1],intervals[pos][1]);
        }
        else{
            result.push_back(ans);
            ans = intervals[pos];
        }
        pos++;
    }
    result.push_back(ans);
    return result;
}

int main(){
    int n = 0;
    cin >> n;
    vector<vector<int>> intervals(n,vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> mergeIntervals = merge(intervals);
    for(int i = 0; i < mergeIntervals.size(); i++){
        for(int j = 0; j < 2; j++){
            cout << mergeIntervals[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}