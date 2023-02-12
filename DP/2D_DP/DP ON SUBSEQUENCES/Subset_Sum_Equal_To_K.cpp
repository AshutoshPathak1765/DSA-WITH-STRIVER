// Problem Link:- https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // dp(i,s) -> check if it is possible to make a sum of s using the elements [0.....i]
    // final answer-> dp(n-1,k)
    // dp(i,s)=dp(i-1,s)|dp(i-1,s-arr[i])
    // Base Case-> dp(i,0)=true
    // if(arr[0]<=k) dp(0,arr[0])=true
    bool dp[n][k + 1];
    for (int i = 0; i < n; i++)
        for (int sum = 0; sum <= k; sum++)
            dp[i][sum] = false;
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= k; sum++) {
            bool op1 = dp[i - 1][sum];
            bool op2 = (sum >= arr[i]) ? dp[i - 1][sum - arr[i]] : false;
            dp[i][sum] = (op1 || op2);
        }
    }
    return dp[n - 1][k];
}