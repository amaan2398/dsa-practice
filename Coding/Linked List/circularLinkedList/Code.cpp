/*
@ Creator: Amaan Shaikh
@ Problem_Title: circularLinkedList
    @ Problem_Statement: Define Circular Linked List Data Structure and build code for InsertAtTail, InsertAtHead, Display, deletion and deletionAtHead.
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 23:05:26
*/

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* newNode = new node(val);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    node* ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
    }
    node* newNode = new node(val);
    node* ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next= newNode;
    newNode->next = head;
}

int deleteAtHead(node* &head){
    if(head == NULL){
        return -1;
    }
    if(head->next == head){
        node* todelete = head;
        head = NULL;
        delete todelete;
        return 0;
    }
    node* ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    node* todelete = head;
    ptr->next = head->next;
    head = head->next;
    delete todelete;
    return 0;
}

void deletion(node* &head, int val){
    if(head == NULL){
        return;
    }
    if(head->data == val){
        deleteAtHead(head);
        return;
    }
    node* ptr = head;
    while(ptr->next->data == val){
        ptr = ptr->next;
        if(ptr == head){
            return;
        }
    }
    node* todelete = ptr->next;
    ptr->next = ptr->next->next;
    delete todelete;
}

void display(node* head){
    if(head == NULL){
        cout << "NULL" << endl;
        return;
    }
    node* ptr = head;
    do{
        cout << ptr->data << "->";
        ptr = ptr->next;
    }while(ptr!= head);
    cout << head->data << "->..." << endl;
}

int main(){
    node* Head = NULL; 
    display(Head);
    insertAtHead(Head, 0);
    display(Head);
    insertAtHead(Head, 1);
    insertAtHead(Head, 2);
    display(Head);
    insertAtHead(Head, 3);
    insertAtHead(Head, 4);
    display(Head);
    insertAtTail(Head, 5);
    insertAtTail(Head, 6);
    display(Head);
    insertAtTail(Head, 7);
    insertAtTail(Head, 8);
    display(Head);
    deletion(Head,5);
    display(Head);
    deletion(Head,10);
    display(Head);
    deletion(Head,4);
    display(Head);
    for(int i = 0; i < 10; i++){
        cout << deleteAtHead(Head) << endl;
        display(Head);
    }
    return 0;
}