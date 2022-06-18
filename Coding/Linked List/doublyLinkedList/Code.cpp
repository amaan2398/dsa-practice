/*
@ Creator: Amaan Shaikh
@ Problem_Title: doublyLinkedList
    @ Problem_Statement: Define Doubly Linked List Data Structure and build code for InsertAtTail, InsertAtHead, Display, deletion and deletionAtHead.
    @ Data_Structure: Doubly Linked List
    @ Algorithm: None
    @ Level: Easy
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 13:06:59
*/

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* newNode = new node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = head->prev;
}

void insertAtTail(node* &head, int val){
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* newNode = new node(val);
    node* iter = head;
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = newNode;
    newNode->prev = iter;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(node* &head, int val){
    node* iter = head;
    if(iter->data == val){
        deleteAtHead(head);
        return;
    }
    while(iter->next->data != val){
        iter = iter->next;
    }
    node* todelete = iter->next;
    iter->next = iter->next->next;
    iter->next->prev = iter;
    delete todelete;
}

void display(node* head){
    node* iter = head;
    while(iter!= NULL){
        cout << iter->data << "<=>";
        iter = iter->next;
    }
    cout << "NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head,10);
    insertAtHead(head,9);
    insertAtTail(head,11);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    display(head);
    deletion(head,10);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}