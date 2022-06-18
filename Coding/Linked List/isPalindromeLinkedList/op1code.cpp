/*
@ Creator: Amaan Shaikh
@ Problem_Title: isPalindromeLinkedList
    @ Problem_Statement: Given the head of a singly linked list, return true if it is a palindrome.
    @ Data_Structure: Linked List
    @ Algorithm: revese and mid of linked list combo
    @ Level: Easy
    @ URL: https://leetcode.com/problems/palindrome-linked-list/
@ Approach: Optimized Approach 1
@ Date_Time: June 19, 2022 01:05:28
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

ListNode* reverseLinkedList(ListNode* &Head){
    if((Head==NULL) || (Head->next == NULL)){
        return Head;
    }
    ListNode* newHead = reverseLinkedList(Head->next);
    Head->next->next = Head;
    Head->next = NULL;
    return newHead;
}
ListNode* midNode(ListNode* &Head){
    ListNode* fast = Head;
    ListNode* slow = Head;
    while((fast!=NULL) and (fast->next != NULL)){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == NULL){
        return slow;
    }
    return slow->next;
}
bool isPalindrome(ListNode* head) {
    ListNode* mid = midNode(head);
    mid = reverseLinkedList(mid);
    ListNode* ptr = head;
    while(mid != NULL){
        if(ptr->data != mid->data){
            return false;
        }
        mid = mid->next;
        ptr = ptr->next;
    }
    return true;
}

int main(){
    ListNode* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    display(Head);
    cout << isPalindrome(Head) << endl;
    Head = NULL;
    insertAtTail(Head, 0);
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 3);
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    insertAtHead(Head, 1);
    insertAtHead(Head, 2);
    insertAtHead(Head, 3);
    insertAtHead(Head, 4);
    insertAtHead(Head, 5);
    display(Head);
    cout << isPalindrome(Head) << endl;
    return 0;
}