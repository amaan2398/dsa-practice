/*
@ Creator: Amaan Shaikh
@ Problem_Title: queueIntro
    @ Problem_Statement: Implament Queue from scratch.
    @ Data_Structure: Queue
    @ Algorithm: 
    @ Level: School
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: July 13, 2022 23:25:55
*/

#include<bits/stdc++.h>

using namespace std;

class CustomQueue{
    private:
    int maxsize;
    int *container;
    int head;
    int tail;
    public:
    CustomQueue(int capacity){
        container = new int[capacity];
        maxsize = capacity;
        head = -1;
        tail = -1;
    }

    int getCapacity(){
        return maxsize; 
    }

    bool enQueue(int val){
        if((tail+1) >= maxsize){
            cout << "Overflow !" << endl;
            return false;
        }
        container[++tail] = val;
        return true;
    }

    bool deQueue(){
        if(empty() || ((tail+1) >= maxsize)){
            cout << "Underflow !" << endl;
            return false;
        }
        ++head;
        return true;
    }

    int peek(){
        if(empty()){
            cout << "No element in queue !" << endl;
            return -1;
        }
        return container[(head+1)];
    }

    bool empty(){
        return (head >= tail);
    }
};

int main(){
    CustomQueue q = CustomQueue(10);
    for(int i = 0;i < 5; i++){
        if(!q.enQueue(i+1)){
            cout << "Break" << endl;
            break;
        }
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
        if(!q.enQueue(i+1)){
            cout << "Break" << endl;
            break;
        }
        cout << q.peek() << endl;
    }
    return 0;
}