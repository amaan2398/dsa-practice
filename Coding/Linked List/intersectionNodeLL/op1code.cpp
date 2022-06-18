/*
@ Creator: Amaan Shaikh
@ Problem_Title: intersectionNodeLL
    @ Problem_Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
    @ Data_Structure: Linked List
    @ Algorithm: 2Pointers
    @ Level: Easy
    @ URL: https://leetcode.com/problems/intersection-of-two-linked-lists/
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 22:29:50
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* A = headA;
    ListNode* B = headB;
    int lenA = 1, lenB = 1;
    while(A->next != NULL){
        A = A->next;
        lenA++;
    }
    while(B->next != NULL){
        B = B->next;
        lenB++;
    }
    A = headA;
    B = headB;
    
    if(lenA>lenB){
        int diff = lenA-lenB;
        for(int i = 1; i <= diff; i++){
            A = A->next;
        }
    }
    else if(lenB>lenA){
        int diff = lenB-lenA;
        for(int i = 1; i <= diff; i++){
            B = B->next;
        }
    }
    while(A != B){
        A = A->next;
        B = B->next;
    }
    return A;
}

int main(){
    ListNode* HeadA = NULL;
    ListNode* HeadB = NULL;
    insertAtTail(HeadA, 1);
    insertAtTail(HeadA, 2);
    insertAtTail(HeadA, 3);
    insertAtTail(HeadA, 4);
    insertAtTail(HeadA, 5);
    display(HeadA);
    insertAtTail(HeadB,6);
    insertAtTail(HeadB,7);
    insertAtTail(HeadB,8);
    HeadB->next->next->next = HeadA->next->next;
    display(HeadB);
    ListNode* node = getIntersectionNode(HeadA,HeadB);
    display(node);
    return 0;
}