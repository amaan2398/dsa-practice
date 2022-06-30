/*
@ Creator: Amaan Shaikh
@ Problem_Title: distanceOfNearestCellHaving1
    @ Problem_Statement: Given a binary grid of n*m. Find the distance of nearest 1 in the grid for each cell. The distance is calculated as |i1  i2| + |j1  j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
    @ Data_Structure: Queue
    @ Algorithm: None
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 20:56:17
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>>grid)
{
    // Code here
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> ans(rows,vector<int>(cols,INT_MAX));
    queue<pair<int,int>> q;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 1){
                ans[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()){
        pair<int,int> point = q.front();
        q.pop();
        int val = ans[point.first][point.second];
        //up
        if((point.first-1 >= 0) and (ans[(point.first-1)][point.second]> (val+1))){
            ans[(point.first-1)][point.second] = (val+1);
            q.push(make_pair((point.first-1),point.second));
        }
        //down
        if((point.first+1 < rows) and (ans[(point.first+1)][point.second]> (val+1))){
            ans[(point.first+1)][point.second] = (val+1);
            q.push(make_pair((point.first+1),point.second));
        }
        //left
        if((point.second-1 >= 0) and (ans[point.first][(point.second-1)]> (val+1))){
            ans[point.first][(point.second-1)] = (val+1);
            q.push(make_pair(point.first, (point.second-1)));
        }
        //right
        if((point.second+1 < cols) and (ans[point.first][(point.second+1)]> (val+1))){
            ans[point.first][(point.second+1)]= (val+1);
            q.push(make_pair(point.first, (point.second+1)));
        }
    }
    return ans;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans = nearest(grid);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
    return 0;
}