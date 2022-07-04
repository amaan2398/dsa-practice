/*
@ Creator: Amaan Shaikh
@ Problem_Title: printAllPermutationsNonDistEle
    @ Problem_Statement: Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.
    @ Data_Structure: String
    @ Algorithm: None/ Permutation
    @ Level: Medium
    @ URL: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/#
@ Approach: Optimized Approach 1
@ Date_Time: July 04, 2022 22:43:52
*/

#include<bits/stdc++.h>

using namespace std;

vector<string> ans;
void permute(string& S, string PS){
    if(0 == S.size()){
        ans.push_back(PS);
        return;
    }
    for(int i = 0; i < S.size(); i++){
        if((i<(S.size()-1)) and S[i] == S[i+1]){
            continue;
        }
        string res = S.substr(0,i)+S.substr(i+1);
        permute(res,PS+S[i]);
    }
    return;
}
vector<string>find_permutation(string S)
{
    // Code here there
    sort(S.begin(),S.end());
    permute(S,"");
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = find_permutation(s);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}