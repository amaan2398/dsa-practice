/*
@ Creator: Amaan Shaikh
@ Problem_Title: transformToSumTree
    @ Problem_Statement: Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.
    @ Data_Structure: Binary Tree
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
@ Approach: Optimized Approach 1
@ Date_Time: July 19, 2022 06:38:20
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

void toSumTree(Node *node)
{
    // Your code here
    if(node == NULL){
        return;
    }
    int leftD = 0;
    if(node->left != NULL){
        leftD += node->left->data;
    }
    toSumTree(node->left);
    if(node->left != NULL){
        leftD += node->left->data;
    }
    int rightD = 0;
    if(node->right != NULL){
        rightD += node->right->data;
    }
    toSumTree(node->right);
    if(node->right != NULL){
        rightD += node->right->data;
    }
    node->data = leftD+rightD;
}

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
    toSumTree(root);
    vector<int> ans = preOrder(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout <<endl;
    
    return 0;
}