/*
@ Creator: Amaan Shaikh
@ Problem_Title: lowestCommonAncestor(LCA)
    @ Problem_Statement: Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present. LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.
    @ Data_Structure: Binary Tree [vector/array]
    @ Algorithm: LCA
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
@ Approach: Broad Force
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

bool LCA(Node* root, int val, vector<Node *> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root);
    if(root->data == val){
        return true;
    }
    if(LCA(root->left,val,path)||LCA(root->right,val,path)){
        return true;
    }
    path.pop_back();
    return false;
}

//Function to return the lowest common ancestor in a Binary Tree.
Node* lca(Node* root ,int n1 ,int n2 )
{
    vector<Node *> path1, path2;
    if(!LCA(root,n1,path1) || !LCA(root,n2,path2)){
        return NULL;
    }
    int pos = 0;
    int n = min(path1.size(),path2.size());
    for(; pos < n; pos++){
        if(path1[pos] != path2[pos]){
            break;
        }
    }
    return path1[pos-1];
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