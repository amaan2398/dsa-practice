/*
@ Creator: Amaan Shaikh
@ Problem_Title: mergeTwoSortedLists
    @ Problem_Statement: ou are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.
    @ Data_Structure: Linked List
    @ Algorithm: 2-3pointers
    @ Level: Easy
    @ URL: https://leetcode.com/problems/merge-two-sorted-lists/
@ Approach: Optimized Approach 2
@ Date_Time: June 18, 2022 22:56:48
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    if(list1->data < list2->data){
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }
    else if(list2->data <= list1->data){
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
    return NULL;
}

int main(){
    ListNode* Head1 = NULL;
    ListNode* Head2 = NULL;
    insertAtTail(Head1, 1);
    insertAtTail(Head2, 2);
    insertAtTail(Head1, 3);
    insertAtTail(Head2, 4);
    insertAtTail(Head1, 5);
    display(Head1);
    display(Head2);
    ListNode* newHead = mergeTwoLists(Head1,Head2);
    display(newHead);
    return 0;
}