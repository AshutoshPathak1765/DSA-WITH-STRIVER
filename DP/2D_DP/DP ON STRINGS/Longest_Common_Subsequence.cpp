// Problem Link:- https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
#include <bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
	// dp(i,j) -> Longest Common Subsequence of the strings s and t having lengths i and j respectively
	// final answer-> dp(n,m)
	// Recurrence->
	//  dp(i,j)= 1+dp(i-1,j-1) if the ith character of s matches with the jth character of t
	// 		   = dp(i-1,j) if the ith character of s doesn't match with the jth character of t
	//		   = dp(i,j-1) if the jth character of t doesn't match with the ith character of s
	// dp(i,j)=max(1+dp(i-1,j-1),dp(i-1,j),dp(i,j-1))
	// Base Case->
	// dp(i,0)=dp(0,j)=0
	int n = s.size(), m = t.size();
	int dp[n + 1][m + 1];

	// Base Cases

	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	// Calculating the answer for remaining part of the array
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int op1 = (s[i - 1] == t[j - 1] ? 1 + dp[i - 1][j - 1] : 0);
			int op2 = dp[i - 1][j];
			int op3 = dp[i][j - 1];
			dp[i][j] = max(op1, max(op2, op3));
		}
	}
	// returning the final answer
	return dp[n][m];
}