/*
@ Creator: Amaan Shaikh
@ Problem_Title: pascalsTriangle
    @ Problem_Statement: Given an integer n, return the first n of Pascal's triangle.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/pascals-triangle/
@ Approach: Optimized Approach 1
@ Date_Time: June 06, 2022 23:52:08
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<long long int>> printPascal(int numRows) {
    vector<vector<long long int>> ans(numRows);
    for(int i = 0; i < numRows; i++){
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        
        for(int j = 1; j < i; j++){
            ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}

int main(){
    long long int n = 0;
    cin >> n;
    vector<vector<long long int>> ans = printPascal(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}