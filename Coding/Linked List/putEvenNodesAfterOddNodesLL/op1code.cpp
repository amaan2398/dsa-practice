/*
@ Creator: Amaan Shaikh
@ Problem_Title: putEvenNodesAfterOddNodesLL
    @ Problem_Statement: Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.The first node is considered odd, and the second node is even, and so on. Note that the relative order inside both the even and odd groups should remain as it was in the input. You must solve the problem in O(1) extra space complexity and O(n) time complexity.
    @ Data_Structure: Linked List
    @ Algorithm: 2 pointers
    @ Level: Medium
    @ URL: https://leetcode.com/problems/odd-even-linked-list/
@ Approach: Optimized Approach 1
@ Date_Time: June 19, 2022 01:20:26
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

ListNode* oddEvenList(ListNode* head) {
    if((head == NULL)||(head->next == NULL)||(head->next->next == NULL)){
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* ptr1 = odd;
    ListNode* ptr2 = even;
    while((ptr1->next != NULL) && (ptr2->next != NULL)){
        ptr1->next = ptr2->next;
        ptr1 = ptr1->next;
        if(ptr1->next == NULL){
            break;
        }
        ptr2->next = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = even;
    ptr2->next = NULL;
    return odd;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    ListNode* newHead = oddEvenList(Head);
    display(newHead);
    return 0;
}