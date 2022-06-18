/*
@ Creator: Amaan Shaikh
@ Problem_Title: linkedListIntro
    @ Problem_Statement: Define Linked List Data Structure and build code for InsertAtTail, InsertAtHead, Display, Search and deletion, deletionAtHead.
    @ Data_Structure: Linked List
    @ Algorithm: None
    @ Level: Easy
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: June 18, 2022 08:26:38
*/

#include<bits/stdc++.h>

using namespace std;

//Defination of Linked List
class Node{
    public:
        int data;
        Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &Head, int val){
    Node* node = new Node(val);
    node->next = Head;
    Head = node;
}

void insertAtTail(Node* &Head, int val){
    if(Head == NULL){
        insertAtHead(Head, val);
        return;
    }
    Node* node = new Node(val);
    Node* temp = Head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp-> next = node;
    
}

int search(Node* Head, int key){
    int pos = 0;
    while(Head!=NULL){
        if(Head->data == key){
            return pos;
        }
        Head = Head->next;
        pos++;
    }
    return -1;
}

int deleteAtHead(Node* &Head){
    if(Head == NULL){
        return -1;// data to be deleted not found;
    }
    Node* todelete = Head;
    Head = Head->next;
    delete todelete;
    return 0;//Deleted data returning 0;
}

int deletion(Node* &Head, int val){

    if((Head == NULL) or (Head->data == val)){
        return deleteAtHead(Head);
    }

    Node* temp = Head;
    while((temp->next != NULL) and (temp->next->data != val)){
        temp = temp->next;
    }
    if(temp->next == NULL){
        return -1; // data to be deleted not found;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return 0; //Deleted data returning 0;
}

void display(Node* Head){
    Node* temp = Head;
    while(temp!= NULL){
        cout << (temp->data) << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* Head = NULL; 
    insertAtHead(Head, 0);
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
    cout << search(Head,5) << endl;
    cout << search(Head,9) << endl;
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