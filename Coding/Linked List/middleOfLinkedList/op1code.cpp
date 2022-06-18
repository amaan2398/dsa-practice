/*
@ Creator: Amaan Shaikh
@ Problem_Title: middleOfLinkedList
    @ Problem_Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
    @ Data_Structure: Linked List
    @ Algorithm: Hare and tortoise
    @ Level: Easy
    @ URL: https://leetcode.com/problems/middle-of-the-linked-list/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 11:53:04
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

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while((fast != NULL) and (fast->next != NULL)){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    ListNode* middle = middleNode(Head);
    display(middle);
    return 0;
}