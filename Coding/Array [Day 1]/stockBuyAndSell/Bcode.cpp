/*
@ Creator: Amaan Shaikh
@ Problem_Title: stockBuyAndSell
    @ Problem_Statement: You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
    
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
    @ Data_Structure: Array
    @ Algorithm: None
    @ Level: Easy
    @ URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
@ Approach: Broad Force
@ Date_Time: June 08, 2022 01:43:45
*/

#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices){
    int profit = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            if(profit < (prices[j] - prices[i])){
                profit = prices[j]-prices[i];
            }
        }
    }
    return profit;
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> prices(n,0);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    cout << maxProfit(prices) << endl;
    return 0;
}