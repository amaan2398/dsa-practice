/*
@ Creator: Amaan Shaikh
@ Problem_Title: setMatrixZeroes
    @ Problem_Statement: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. [Note: You must do it in place.]
    @ Data_Structure: Array, 2D Array, Matrix
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/set-matrix-zeroes/
@ Approach: Broad Force
@ Date_Time: June 06, 2022 22:56:55
*/

#include<bits/stdc++.h>

using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    // Storing matrix dimensions in variables.
    int lenRow = matrix.size();
    int lenCol = matrix[0].size();
    
    // Tracking zeros present in matrix using [map/dict/hashmap]
    map<int,bool> posZeroRow;
    map<int,bool> posZeroCol;
    
    // Initializing trackers
    for(int i = 0; i < lenRow; i++){
        posZeroRow[i] = 0;
    }
    for(int i = 0; i < lenCol; i++){
        posZeroCol[i] = 0;
    }
    
    // Populating values in map
    for(int i = 0; i < lenRow; i++){
        for(int j= 0; j < lenCol; j++){
            if(matrix[i][j] == 0){
                posZeroRow[i]=1;
                posZeroCol[j]=1;
            }
        }
    }
    
    // Utilization of trackers
    for(int i = 0; i < lenRow; i++){
        for(int j= 0; j < lenCol; j++){
            if(posZeroRow[i] or posZeroCol[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}