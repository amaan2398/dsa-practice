/*
@ Creator: Amaan Shaikh
@ Problem_Title: courseSchedule
    @ Problem_Statement: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai. For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1. Return true if you can finish all courses. Otherwise, return false.
    @ Data_Structure: Graph
    @ Algorithm: DFS/BFS used this solution is of DFS
    @ Level: Medium
    @ URL: https://leetcode.com/problems/course-schedule/
@ Approach: Optimized Approach 1
@ Date_Time: June 30, 2022 21:11:40
*/

#include<bits/stdc++.h>

using namespace std;

enum states{ D, N, A};
bool DFS(vector<int>* adj, vector<bool> &visited, vector<states> &acceptable, int curr){
    if(not visited[curr]){
        if(acceptable[curr] == N){
            return false;
        }
        else if(acceptable[curr] == A){
            return true;
        }
        visited[curr] = true;
        for(int i = 0; i < adj[curr].size(); i++){
            if(not DFS(adj,visited,acceptable,adj[curr][i])){
                acceptable[curr] = N;
                return false;
            }
        }
        visited[curr] = false;
        acceptable[curr] = A;
        return true;
    }
    acceptable[curr] = N;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    int n = prerequisites.size();
    vector<bool> visited(numCourses,false);
    vector<states> acceptable(numCourses,D);
    for(int i = 0; i < n; i++){
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for(int i = 0; i < numCourses; i++){
        if (not DFS(adj,visited,acceptable,i)){
            return false;
        }
    }
    return true;
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> arr(m,vector<int>(2,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    cout << canFinish(n,arr);
    return 0;
}