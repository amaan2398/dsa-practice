/*
@ Creator: Amaan Shaikh
@ Problem_Title: imageMatrixRotation
    @ Problem_Statement: You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
    @ Data_Structure: 2d Array
    @ Algorithm: None [Matrix Traspose -> flip horizontally]
    @ Level: Medium
    @ URL: https://leetcode.com/problems/rotate-image/
@ Approach: Optimized Approach 1
@ Date_Time: June 08, 2022 03:27:02
*/

#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix, int n) {
    // Traspose of matrix
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // Flip horizontally 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n/2); j++){
            swap(matrix[i][j],matrix[i][(n-1)-j]);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    rotate(mat,n);
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
