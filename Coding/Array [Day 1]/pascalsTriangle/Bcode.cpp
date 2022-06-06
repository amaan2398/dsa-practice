/*
@ Creator: Amaan Shaikh
@ Problem_Title: pascalsTriangle
    @ Problem_Statement: Given an integer n, return the first n of Pascal's triangle.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/pascals-triangle/
@ Approach: Broad Force
@ Date_Time: June 06, 2022 23:52:08
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<long long int>> printPascal(int n) {
    if(n == 1){ // Base case 1 for recursion 
        return {{1}};
    }
    else if(n == 2){ // Base case 2 for recursion
        return {{1},{1,1}};
    }
    vector<vector<long long int>> ans; // Final result vector
    ans = printPascal(n-1); // Recursion call n-1 values 
    // Other words, ans will having n-1 pascal rows 
    // Now below,
    // 1. We will find nth row
    int lenAns = ans.size();
    vector<long long int> currRow = {1};
    // Part 1 
    for(int i = 1; i < ans[lenAns-1].size(); i++){
        currRow.push_back(ans[lenAns-1][i-1]+ans[lenAns-1][i]);
    }
    // Part 2 [Mirror of part 1 with some skip]
    int lenCurrRow = currRow.size();
    int pascalRowMirrorPos = (lenCurrRow-(n-1));
    for(int i = pascalRowMirrorPos; i >= 0; i--){
        currRow.push_back(currRow[i]);
    }
    // 2. append in result vector
    ans.push_back(currRow);
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