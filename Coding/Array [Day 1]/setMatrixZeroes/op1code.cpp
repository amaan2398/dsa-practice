/*
@ Creator: Amaan Shaikh
@ Problem_Title: setMatrixZeroes
    @ Problem_Statement: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. [Note: You must do it in place.]
    @ Data_Structure: Array, 2D Array, Matrix
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/set-matrix-zeroes/
@ Approach: Optimized Approach 1
@ Date_Time: June 06, 2022 22:56:55
*/

#include<bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    // Storing matrix dimensions in variables.
    int lenRow = matrix.size();
    int lenCol = matrix[0].size();
    
    bool isZeroInDumCol = false;
    bool isZeroInDumRow = false;
    
    // Using 1st row and 1st col as trackers
    for(int i = 0; i < lenRow; i++){
        for(int j= 0; j < lenCol; j++){
            if(matrix[i][j] == 0){
                if(i == 0){
                    isZeroInDumCol = true;
                }
                if(j == 0){
                    isZeroInDumRow = true;
                }
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    
    // Utilization of trackers
    for(int i = 1; i < lenRow; i++){
        for(int j= 1; j < lenCol; j++){
            if((matrix[i][0] == 0) or (matrix[0][j] == 0)){
                matrix[i][j] = 0;
            }
        }
    }

    // Converting 1st row values to zero if 1st row has zero
    if(isZeroInDumRow){
        for(int i = 0; i < lenRow; i++){
            matrix[i][0] = 0;
        }
    }

    // Converting 1st col values to zero if 1st col has zero
    if(isZeroInDumCol){
        for(int j = 0; j < lenCol; j++){
            matrix[0][j] = 0;
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