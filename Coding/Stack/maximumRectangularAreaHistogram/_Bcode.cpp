/*
@ Creator: Amaan Shaikh
@ Problem_Title: maximumRectangularAreaHistogram
    @ Problem_Statement: 
    @ Data_Structure: 
    @ Algorithm:
    @ Level: 
    @ URL: 
@ Approach: Broad Force
@ Date_Time: July 15, 2022 21:27:03
*/

#include<bits/stdc++.h>

using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<long long> data;
    for(int i = 0; i < n; i++){
        data.push_back(arr[i]);
    }
    data.push_back(0);
    stack<long long> st;
    long long ans = 0;
    for(int i = 0; i <= n; i++){
        while((!st.empty())and (data[st.top()] > data[i])){
            long long pos = st.top();
            long long h = data[pos];
            st.pop();
            if(st.empty()){
                long long v = h*i;
                ans = max(ans, v);
            }
            else{
                long long v = h*((i-st.top())-1);
                ans = max(ans, v);
            }
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << getMaxArea(arr,n)<<endl;
    return 0;
}