/*
@ Creator: Amaan Shaikh
@ Problem_Title: stackUsingQueue
    @ Problem_Statement: Implement a Stack using two queues q1 and q2.
    @ Data_Structure: Queue
    @ Algorithm: Stack
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/#
@ Approach: Optimized Approach 2
@ Date_Time: July 15, 2022 03:19:29
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
    QueueStack qs;
    int Q;
    cin>>Q;
    while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs.push(a);
        }else{
            cout<<qs.pop()<<" ";
        }
    }
}

void QueueStack :: push(int x)
{
    q1.push(x);
}

int QueueStack :: pop()
{
    if(q1.empty()){
        return -1;
    }
    int x = 0;
    while(!q1.empty()){
        x = q1.front();
        q1.pop();
        if(q1.empty()){
            break;
        }
        q2.push(x);
        
    }
    q1.swap(q2);
    return x;
}