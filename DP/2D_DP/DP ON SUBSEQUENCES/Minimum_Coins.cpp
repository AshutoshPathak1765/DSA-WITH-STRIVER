// Problem Link:- https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21
#include <bits/stdc++.h>
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // dp(i,s)-> Minimum number of elements needed to reach the sum of s using the elements from [0..i]
    // final answer-> dp(n-1,x)
    // Recurrence-> dp(i,s)=min(dp(i-1,x),1+dp(i,x-num[i]))
    // Base Case -> dp(0,s)=s/num[0] if s%arr[0]==0 for all s>=0 && s<=x
    // else dp(0,s)=1e9(not possible) if s%arr[0]!=0

    int n = num.size();
    int dp[n][x + 1];
    // base case
    for (int s = 0; s <= x; s++)
        if (s % num[0] == 0)
            dp[0][s] = s / num[0];
        else
            dp[0][s] = 1e9;
// calcuating for the remaining array
    for (int i = 1; i < n; i++) {
        for (int s = x; s >= 0; s--) {
            int op1 = dp[i - 1][s];
            int op2 = (s >= num[i]) ? 1 + dp[i][s - num[i]] : 1e9;
            dp[i][s] = min(op1, op2);
        }
    }
//  checking if the answer is valid or not if its valid return the answer or return -1
    int val = dp[n - 1][x];
    return (val == 1e9 ? -1 : val);
}