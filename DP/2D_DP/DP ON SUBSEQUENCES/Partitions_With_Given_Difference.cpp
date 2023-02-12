// Problem Link:- https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19
#include <bits/stdc++.h>
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    // dp(i,s)-> Number of ways to make a sum of s using the array elements from [0...i]
    // final answer-> dp(n,(sum+d)/2)
    // Recurrence-> dp(i,s)=dp(i-1,s)+dp(i-1,s-arr[i])
    // Base Case-> dp(i,0)=1 for all i from [0...n-1]
    // dp(0,arr[0])=1 if arr[0]!=0 and dp(0,0)=2 if arr[0]=2
    // if sum+d is odd return false
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
//  if sum+d is odd return 0
    if ((sum + d) & 1)
        return 0;

    int dp[n][(sum + d) / 2 + 1];
    const int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
        for (int s = 0; s <= (sum + d) / 2; s++)
            dp[i][s] = 0;
    // dp(i,0)=1 for all i from [0...n-1]
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    // dp[0][arr[0]]=1 if arr[0]<=sum
    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;
    // important edge case if arr[0]=0 then there are two valid subsets {},{0} such that whose sum is zero
    if (arr[0] == 0)
        dp[0][0] = 2;
    // compute the answer for the remaining array
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= (sum + d) / 2; s++) {
            int op1 = dp[i - 1][s];
            int op2 = (s >= arr[i]) ? dp[i - 1][s - arr[i]] : 0;
            dp[i][s] = (op1 + op2) % mod;
        }
    }
    // return the final answer
    return dp[n - 1][(sum + d) / 2];
}


