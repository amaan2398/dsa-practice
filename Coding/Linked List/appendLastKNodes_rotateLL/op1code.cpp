/*
@ Creator: Amaan Shaikh
@ Problem_Title: appendLastKNodes_rotateLL
    @ Problem_Statement: Given the head of a linked list, rotate the list to the right by k places.
    @ Data_Structure: Linked List
    @ Algorithm: two pointer/len calulate
    @ Level: Medium
    @ URL: https://leetcode.com/problems/rotate-list/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 22:07:37
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

ListNode* rotateRight(ListNode* head, int k) {
    if((head == NULL) || (head->next == NULL) || (k == 0)){
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    int len = 1;
    while(fast->next != NULL){
        len++;
        if(len > k){
            break;
        }
        fast = fast->next;
    }
    if(fast->next == NULL){
        k = k%len;
        if(k == 0){
            return head;
        }
    }
    fast = head;
    for(int i = 1; i <= k; i++){
        fast = fast->next;
    }
    if(fast==NULL){
        return slow;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next =  head;
    ListNode* newHead = slow->next;
    slow->next = NULL;
    return newHead;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    ListNode* newHead = rotateRight(Head,3);
    display(newHead);
    return 0;
}