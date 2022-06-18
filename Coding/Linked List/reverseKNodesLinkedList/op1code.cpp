/*
@ Creator: Amaan Shaikh
@ Problem_Title: reverseKNodesLinkedList
    @ Problem_Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. You may not alter the values in the list's nodes, only nodes themselves may be changed.
    @ Data_Structure: Linked List
    @ Algorithm: combo of linear and recursion reverse 
    @ Level: Hard
    @ URL: https://leetcode.com/problems/reverse-nodes-in-k-group/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 10:19:20
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

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL){
        return head;
    }
    int count = 0;
    ListNode* currNode = head;
    while((currNode!=NULL) and (count != k)){
        count++;
        currNode = currNode->next;
    }
    if(count < k){
        return head;
    }
    ListNode* tail = reverseKGroup(currNode,k);
    ListNode* prevNode = NULL;
    currNode = head;
    ListNode* nextNode;
    count = 0;
    while((currNode!=NULL) and (count != k)){
        count++;
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head->next=tail;
    return prevNode;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    ListNode* newHead = reverseKGroup(Head,2);
    display(newHead);
    return 0;
}