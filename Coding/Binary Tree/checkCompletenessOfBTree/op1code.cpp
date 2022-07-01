/*
@ Creator: Amaan Shaikh
@ Problem_Title: checkCompletenessOfBTree
    @ Problem_Statement: Given the root of a binary tree, determine if it is a complete binary tree. In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
    @ Data_Structure: Binary Tree
    @ Algorithm: Level order traversal 
    @ Level: Medium
    @ URL: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
@ Approach: Optimized Approach 1
@ Date_Time: July 01, 2022 11:06:01
*/

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    public:
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isCompleteTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool isNull = false;
    while(!q.empty()){
        int n = q.size();
        while(n){
            Node* temp = q.front();
            q.pop();
            n--;
            if(temp->left != NULL){
                if(isNull){
                    return false;
                }
                q.push(temp->left);
                
            }
            else{
                isNull = true;
            }
            if(temp->right != NULL){
                if(isNull){
                    return false;
                }
                q.push(temp->right);
            }
            else{
                isNull = true;
            }
            
        }
    }
    return true;
}

void preorder(Node* Head){
    if(Head == NULL){
        return;
    }
    cout << Head->data << " ";
    preorder(Head->left);
    preorder(Head->right);
}

int main(){
    struct Node* Head = NULL;
    Head = new Node(1);
    Head->left = new Node(2);
    Head->right = new Node(3);
    Head->left->left = new Node(4);
    Head->left->right = new Node(5);
    Head->right->left = new Node(6);
    Head->right->right = new Node(7);
    preorder(Head);
    cout << endl;
    cout << isCompleteTree(Head);
    cout << endl;

    struct Node* Head1 = NULL;
    Head1 = new Node(1);
    Head1->left = new Node(2);
    // Head1->right = new Node(3);
    Head1->left->left = new Node(4);
    Head1->left->right = new Node(5);
    // Head1->right->left = new Node(6);
    // Head1->right->right = new Node(7);
    preorder(Head1);
    cout << endl;
    cout << isCompleteTree(Head1);
    cout << endl;

    return 0;
}