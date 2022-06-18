/*
@ Creator: Amaan Shaikh
@ Problem_Title: deleteNode[O(1)]LinkedList
    @ Problem_Statement: Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.
    @ Data_Structure: Linked List
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/delete-node-in-a-linked-list/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 11:58:30
*/

#include<bits/stdc++.h>

using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(ListNode* &Head, int val){
    ListNode* node = new ListNode(val);
    node->next = Head;
    Head = node;
}

void insertAtTail(ListNode* &Head, int val){
    if(Head == NULL){
        insertAtHead(Head, val);
        return;
    }
    ListNode* node = new ListNode(val);
    ListNode* temp = Head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp-> next = node;
}

void display(ListNode* Head){
    ListNode* temp = Head;
    while(temp!= NULL){
        cout << (temp->data) << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(ListNode* node) {
    if(node->next == NULL){
        ListNode* todelete = node;
        node = NULL;
        delete todelete;
        return;
    }
    ListNode* todelete = node->next;
    node->data = node->next->data;
    node->next=node->next->next;
    delete todelete;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    deleteNode(Head->next->next);
    display(Head);
    return 0;
}