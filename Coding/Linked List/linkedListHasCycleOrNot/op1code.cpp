/*
@ Creator: Amaan Shaikh
@ Problem_Title: linkedListHasCycleOrNot
    @ Problem_Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.
    @ Data_Structure: Linked List
    @ Algorithm: Hare and tortoise 
    @ Level: Easy
    @ URL: https://leetcode.com/problems/linked-list-cycle/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 12:30:11
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

void createCycle(ListNode* &head, int val){
    ListNode* node;
    ListNode* iter = head;
    while(iter->next != NULL){
        if(iter->data == val){
            node = iter;
        }
        iter = iter->next;
    }
    iter->next = node;
}

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int count = 0;
    while(((fast != NULL) and (fast->next != NULL)) and ((count==0) or (slow != fast))){
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }
    if((count != 0) and (slow == fast)){
        return true;
    }
    return false;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    cout << hasCycle(Head)<< endl;
    createCycle(Head,3);
    // display(Head);
    cout << hasCycle(Head)<< endl;
    return 0;
}