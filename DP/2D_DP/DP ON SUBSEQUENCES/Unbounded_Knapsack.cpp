// Problem Link:- https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=OgvOZ6OrJoY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=24
#include <bits/stdc++.h>
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // dp(i,W) -> maximum profit earned from the elements [0..i] if maximum allowed weight is W
    // final answer-> dp(n-1,w)
    // Recurrence-> dp(i,W)=max(dp(i-1,W),profit[i]+dp(i,W-weight[i]))
    // Base Case->
    // dp[0][W]=(W/weight[0])*profit[0] if w>=weight[0]
    // dp[0][W]=0   if w<weight[0]

    int dp[n][w + 1];
    // Base Cases
    for (int W = 0; W <= w; W++)
        if (W >= weight[0])
            dp[0][W] = (W / weight[0]) * profit[0];
        else
            dp[0][W] = 0;
    // Calculating the answers for the remaining array
    for (int i = 1; i < n; i++) {
        for (int W = 0; W <= w; W++) {
            int op1 = dp[i - 1][W];
            int op2 = (W >= weight[i]) ? profit[i] + dp[i][W - weight[i]] : 0;
            dp[i][W] = max(op1, op2);
        }
    }
    // return the final answer
    return dp[n - 1][w];
}
