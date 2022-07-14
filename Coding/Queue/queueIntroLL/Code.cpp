/*
@ Creator: Amaan Shaikh
@ Problem_Title: queueIntroLL
    @ Problem_Statement: Implament Queue from scratch using Linked List.
    @ Data_Structure: Queue
    @ Algorithm: 
    @ Level: School
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: July 14, 2022 16:08:58
*/

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CustomQueue{
    private:
    Node* head;
    Node* tail;
    int len;

    public:
    CustomQueue(){
        head = new Node(-1);
        tail = NULL;
        len = 0;
    }

    void enQueue(int val){
        Node* node = new Node(val);
        if(tail == NULL){
            tail = node;
            head->next = node;
        }
        else{
            tail->next = node;
            tail = tail->next;
        }
        len++;
    }

    bool deQueue(){
        if(head->next == NULL){
            cout << "Queue is empty!" << endl;
            return false;
        }
        if(head->next == tail){
            tail = NULL;
        }
        Node* todelete = head->next;
        head->next = head->next->next;  
        delete todelete;
        len--;
        return true;
    }

    int peek(){
        if(head->next == NULL){
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->next->data;
    }

    bool empty(){
        if(len == 0){
            return true;
        }
        return false;
    }
};

int main(){
    CustomQueue q = CustomQueue();
    for(int i = 0;i < 5; i++){
        q.enQueue(i+1);
        cout << q.peek() << endl;
    }

    for(int i = 0;i < 6; i++){
        if(!q.deQueue()){
            cout << "Break" << endl;
            break;
        }
        cout << q.peek() << endl;
    }

    for(int i = 0;i < 11; i++){
        q.enQueue(i+1);
        cout << q.peek() << endl;
        if(!q.deQueue()){
            cout << "Break" << endl;
            break;
        }
    }
    return 0;
}