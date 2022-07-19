/*
@ Creator: Amaan Shaikh
@ Problem_Title: binaryTreeKLevelSumString
    @ Problem_Statement: Given a binary tree and a number K, the task is to find sum of tree nodes at level K. The Binary Tree is given in string form S: (node-value(left-subtree)(right-subtree)).
    @ Data_Structure: String-> Binary Tree
    @ Algorithm: Level Order Traversal 
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/binary-tree-k-level-sum3857/1
@ Approach: Optimized Approach 1
@ Date_Time: July 19, 2022 06:13:35
*/

#include<bits/stdc++.h>

using namespace std;

int kLevelSum(int K, string S) {
    int result = 0;
    int level = -1;
    int n = S.size();
    int num = 0;
    for(int i = 0; i < n; i++){
        if(S[i] == '('){
            result+=num;
            num = 0;
            level++;
        }
        else if(S[i] == ')'){
            result+=num;
            num = 0;
            level--;
        }
        else if(level == K){
            num *= 10;
            num += (S[i]-'0');
        }
    }
    return result;
}

int main(){
    string s;
    int K;
    cin >> K;
    cin >> s;
    cout << kLevelSum(K,s); 
    return 0;
}