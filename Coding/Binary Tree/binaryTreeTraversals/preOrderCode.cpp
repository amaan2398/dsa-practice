/*
@ Creator: Amaan Shaikh
@ Problem_Title: binaryTreeTraversals
    @ Problem_Statement: Given a Binary Tree, find the Pre-Order Traversal of it.
    @ Data_Structure: 
    @ Algorithm: PreOrder Traversal of Binary tree
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/preorder-traversal/1
@ Approach: Approach
@ Date_Time: July 19, 2022 04:11:36
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left,* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector <int> preOrder(Node* root)
{
    vector<int> ans;
    ans.push_back(root->data);
    if(root->left != NULL){
        for(int d: preOrder(root->left)){
            ans.push_back(d);
        }
    }
    if(root->right != NULL){
        for(int d: preOrder(root->right)){
            ans.push_back(d);
        }
    }
    return ans;
}

int main(){
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7 
     /\
    8  9
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    vector<int> ans = preOrder(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout <<endl;
    return 0;
}