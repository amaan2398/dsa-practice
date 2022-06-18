/*
@ Creator: Amaan Shaikh
@ Problem_Title: reveseLinkedList
    @ Problem_Statement: Given the head of a singly linked list, reverse the list, and return the reversed list.
    @ Data_Structure: LinkedList
    @ Algorithm: recusive
    @ Level: Easy-Medium
    @ URL: https://leetcode.com/problems/reverse-linked-list/
@ Approach: Optimized Approach 2
@ Date_Time: June 18, 2022 10:03:21
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

ListNode* reverseList(ListNode* head) {
    
    if(head->next == NULL){
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next=head;
    head->next = NULL;
    return newHead;
}

void display(ListNode* Head){
    ListNode* temp = Head;
    while(temp!= NULL){
        cout << (temp->data) << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    ListNode* NewHead = reverseList(Head);
    display(NewHead);
    return 0;
}