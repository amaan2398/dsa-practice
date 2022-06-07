/*
@ Creator: Amaan Shaikh
@ Problem_Title: matrixRotation
    @ Problem_Statement: Given a 2-dimensional matrix of size ‘N’ x ‘M’, rotate the elements 1 position of the matrix clockwise.
    @ Data_Structure: 2d array
    @ Algorithm: None
    @ Level: Medium-Hard
    @ URL: https://www.codingninjas.com/codestudio/problems/rotate-matrix_981260?topList=striver-sde-sheet-problems&leftPanelTab=0
@ Approach: Optimized Approach 1
@ Date_Time: June 08, 2022 02:06:34
*/

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int startRow, int endRow, int startCol, int endCol){
    return (startRow<=endRow) and (startCol<=endCol);
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int startRow = 0;
    int endRow = n-1;
    int startCol = 0;
    int endCol = m-1;
    int k = 0;
    int val = 0;
    while(isSafe(startRow,endRow,startCol,endCol)){
        //top row
        if ((startRow<endRow) and (startCol<endCol)){//IMP condition
            val = mat[startRow+1][k++];
        }
        else{
            break;
        }
        for(int i = startCol; (i <= endCol) and isSafe(startRow,endRow,startCol,endCol); i++){
            
            int temp = mat[startRow][i];
            mat[startRow][i] = val;
            val = temp;
        }
        startRow++;
        //right col
        for(int i = startRow; (i <= endRow) and isSafe(startRow,endRow,startCol,endCol); i++){
            int temp = mat[i][endCol];
            mat[i][endCol] = val;
            val = temp;
        }
        endCol--;
        //bottom row
        for(int i = endCol; (i >= startCol) and isSafe(startRow,endRow,startCol,endCol); i--){
            int temp = mat[endRow][i];
            mat[endRow][i] = val;
            val = temp;
        }
        endRow--;
        //left col
        for(int i = endRow; (i >= startRow) and isSafe(startRow,endRow,startCol,endCol); i--){
            int temp = mat[i][startCol];
            mat[i][startCol] = val;
            val = temp;
        }
        startCol++;
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
    rotateMatrix(mat,n,m);
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }cout << endl;
    }
    return 0;
}