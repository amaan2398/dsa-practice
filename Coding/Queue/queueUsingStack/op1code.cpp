/*
@ Creator: Amaan Shaikh
@ Problem_Title: queueUsingStack
    @ Problem_Statement: Implement a Queue using two stack s1 and s2.
    @ Data_Structure: Stack
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/queue-using-stack/1/#
@ Approach: Optimized Approach 1
@ Date_Time: July 15, 2022 02:17:47
*/

#include<bits/stdc++.h>

using namespace std;

class CustomQueue {
    private:
    stack<int> input, output;
    public:
    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(output.empty() and input.empty()){
            return -1;
        }
        else if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }
};

int main(){
    CustomQueue q;
    int n = 0;
    cin >> n;
    while(n--){
        int op = 0;
        cin >> op;
        if(op == 1){
            int data = 0;
            cin >> data;
            q.enqueue(data);
        }
        else{
            cout << q.dequeue() << " ";
        }
    }
    return 0;
}