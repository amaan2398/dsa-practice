/*
@ Creator: Amaan Shaikh
@ Problem_Title: stackUsingQueue
    @ Problem_Statement: Implement a Stack using two queues q1 and q2.
    @ Data_Structure: Queue
    @ Algorithm: Stack
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/#
@ Approach: Optimized Approach 1
@ Date_Time: July 15, 2022 02:53:57
*/

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    QueueStack *qs = new QueueStack();
    int Q;
    cin>>Q;
    while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
    }
}

void QueueStack :: push(int x)
{
    q1.push(x);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    q1.swap(q2);
}

int QueueStack :: pop()
{
    if(q2.empty()){
        return -1;
    }
    int x = q2.front();
    q2.pop();
    return x;
}
