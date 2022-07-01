/*
@ Creator: Amaan Shaikh
@ Problem_Title: convertBTreeToMirroTree
    @ Problem_Statement: 
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: July 01, 2022 09:01:16
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

void mirror(Node* node) {
        // code here
    if(node == NULL){
        return;
    }
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
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
    mirror(Head);
    preorder(Head);
    cout << endl;

    return 0;
}