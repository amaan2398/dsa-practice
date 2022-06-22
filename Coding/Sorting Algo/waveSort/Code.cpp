/*
@ Creator: Amaan Shaikh
@ Problem_Title: waveSort
    @ Problem_Statement: Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5]..... If there are multiple solutions, find the lexicographically smallest one.
    @ Data_Structure: Array 
    @ Algorithm: Wave Sort
    @ Level: Easy
    @ URL: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/#
@ Approach: Optimized Approach 1
@ Date_Time: June 22, 2022 07:46:31
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i = 1; i < n; i+=2){
            if(arr[i] > arr[i-1]){
                swap(arr[i],arr[i-1]);
            }
            if(((n-1) > i) && (arr[i] > arr[i+1])){
                swap(arr[i],arr[i+1]);
            }
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends