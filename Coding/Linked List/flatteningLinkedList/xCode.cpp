/*
@ Creator: Amaan Shaikh
@ Problem_Title: flatteningLinkedList
    @ Problem_Statement: checkoutlink
    @ Data_Structure: Linked List
    @ Algorithm: modified merge sort
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
@ Approach: Optimized Approach 1
@ Date_Time: June 19, 2022 00:11:25
*/

#include<bits/stdc++.h>

using namespace std;

Node *flatten(Node *root)
{
   // Your code here
   if((root == NULL) || (root->next == NULL)){
       return root;
   }
   root->next = flatten(root->next);
   Node* dummy = new Node(0);
   Node* ptr1 = root;
   Node* ptr2 = root->next;
   root->next = NULL;
   Node* ptr3 = dummy;
   while((ptr1!=NULL) && (ptr2 != NULL)){
       if(ptr1->data < ptr2->data){
           ptr3->bottom = ptr1;
           ptr1 = ptr1->bottom;
       }
       else{
           ptr3->bottom = ptr2;
           ptr2 = ptr2->bottom;
       }
       ptr3 = ptr3->bottom;
   }
   if(ptr1!=NULL){
       ptr3->bottom = ptr1;
   }
   if(ptr2!=NULL){
       ptr3->bottom = ptr2;
   }
   return dummy->bottom;
}

void worker(){
    cout << "Programmer!"<< endl;
    return;
}

int main(){
    cout << "Hello ";
    worker();
    return 0;
}