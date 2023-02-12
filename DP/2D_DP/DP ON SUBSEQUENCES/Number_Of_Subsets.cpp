// Problem Link:-https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18
#include <bits/stdc++.h>
int findWays(vector<int> &arr, int tar)
{
    // Write your code here.
    // dp(i,s) -> Number of ways to make a sum of s using the array elements from [0...i]
    // final answer-> dp(n-1,k)
    // Recurrence-> dp(i,s)=dp(i-1,s)+dp(i-1,s-arr[i])
    // Base Case-> dp(i,0)=1 for all i from [0...n-1]
    // dp(0,arr[0])=1 if arr[0]<=s
    int n = arr.size();
    int dp[n][tar + 1];
    for (int i = 0; i < n; i++)
        for (int s = 0; s <= tar; s++)
            dp[i][s] = 0;
    // dp(i,0)=1 for all i from [0...n-1]
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    // dp(0,arr[0])=1 if arr[0]<=tar
    if (arr[0] <= tar)
        dp[0][arr[0]] = 1;
    // important edge case if the arr[0]=0 then there are two possible subsets {},{0} to make a sum of 0
    if (arr[0] == 0)
        dp[0][arr[0]] = 2;
    // compute for remaining part of the array
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= tar; s++) {
            int op1 = dp[i - 1][s];
            int op2 = (s >= arr[i]) ? dp[i - 1][s - arr[i]] : 0;
            dp[i][s] = op1 + op2;
        }
    }
    // return the final result
    return dp[n - 1][tar];
}