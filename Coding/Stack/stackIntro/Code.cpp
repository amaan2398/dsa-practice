/*
@ Creator: Amaan Shaikh
@ Problem_Title: stackIntro
    @ Problem_Statement: Implament Stack from scratch.
    @ Data_Structure: Stack
    @ Algorithm: 
    @ Level: School
    @ URL: 
@ Approach: Optimized Approach 1
@ Date_Time: July 07, 2022 22:42:55
*/

#include<bits/stdc++.h>

using namespace std;

class CustomStack{
    private:
    int maxsize;
    int *container;
    int head;
    public:
    CustomStack(int capacity){
        container = new int[capacity];
        maxsize = capacity;
        head = -1;
    }
    
    int getCapacity(){
        return maxsize; 
    }

    bool push(int val){
        if((head+1) >= maxsize){
            cout << "Overflow !" << endl;
            return false;
        }
        container[++head] = val;
        return true;
    }

    bool pop(){
        if(head < 0){
            cout << "Underflow !" << endl;
            return false;
        }
        --head;
        return true;
    }

    int top(){
        if(head < 0){
            cout << "No element in stack !" << endl;
            return -1;
        }
        return container[head];
    }
};

int main(){
    CustomStack st = CustomStack(10);
    for(int i = 0;i < 5; i++){
        if(!st.push(i+1)){
            cout << "Break" << endl;
            break;
        }
        cout << st.top() << endl;
    }

    for(int i = 0;i < 6; i++){
        if(!st.pop()){
            cout << "Break" << endl;
            break;
        }
        cout << st.top() << endl;
    }

    for(int i = 0;i < 11; i++){
        if(!st.push(i+1)){
            cout << "Break" << endl;
            break;
        }
        cout << st.top() << endl;
    }
    return 0;
}