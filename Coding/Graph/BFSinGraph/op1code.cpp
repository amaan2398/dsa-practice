/*
@ Creator: Amaan Shaikh
@ Problem_Title: BFSinGraph
    @ Problem_Statement: Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph.
    @ Data_Structure: Undirected Graph 
    @ Algorithm: BFS
    @ Level: Easy
    @ URL: https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:22:53
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    bool visited[vertex];
    for(int i = 0; i < vertex; i++){
        visited[i] = 0;
    }
    priority_queue<int,vector<int>,greater<int>> adj[vertex];
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i].second].push(edges[i].first);
        adj[edges[i].first].push(edges[i].second);
    }
    vector<int> ans;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        while(!adj[node].empty()){
            if(!visited[adj[node].top()]){
                visited[adj[node].top()] = 1;
                q.push(adj[node].top());
            }
            adj[node].pop();
        }
        if(q.empty()){
            for(int i = 0;i < vertex; i++){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;
                    break;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> arr;
    for(int i = 0;i < m; i++){
        int n1,n2;
        cin >> n1;
        cin >> n2;
        arr.push_back(make_pair(n1,n2));
    }
    vector<int> ans = BFS(n,arr);
    for(int i= 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}