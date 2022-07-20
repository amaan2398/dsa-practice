/*
@ Creator: Amaan Shaikh
@ Problem_Title: lowestCommonAncestor(LCA)
    @ Problem_Statement: Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present. LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.
    @ Data_Structure: Binary Tree
    @ Algorithm: LCA op1
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
@ Approach: Optimized Approach 1
@ Date_Time: July 20, 2022 22:57:53
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* lca(Node* root ,int n1 ,int n2 )
{
    //Your code here
    if(root == NULL){
        return NULL;
    }
    if((root->data == n1) || (root->data == n2)){
        return root;
    }
    Node* leftLCA = lca(root->left,n1,n2);
    Node* rightLCA = lca(root->right,n1,n2);
    if((leftLCA != NULL) && (rightLCA != NULL)){
        return root;
    }
    else if(leftLCA != NULL){
        return leftLCA;
    }
    return rightLCA;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node* ans = lca(root,2,3);
    cout << ans->data << endl;
    Node* root1 = new Node(5);
    root1->left = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    Node* ans1 = lca(root1,4,3);
    cout << ans1->data << endl;
    return 0;
}