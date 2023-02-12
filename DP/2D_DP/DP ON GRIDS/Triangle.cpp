// Problem Link:- https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=SrP-PiLSYC0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=12

#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	// dp(i,j) -> Minimum Path Sum from the cell (i,j) to the cell (n-1,x)
	// Final Answer-> dp(0,0)
	// Recurrence-> dp(i,j)=min(triangle[i][j]+dp(i+1,j),triangle[i][j]+dp(i,j+1))
	// Base Case-> dp(n-1,x)=triangle[n-1][x]

	int dp[n][n];
	// fill the dp table for the last row
	for (int j = 0; j < n; j++)
		dp[n - 1][j] = triangle[n - 1][j];
	// calculate the dp table for the remaining rows
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			// move to the diagonal
			int diag = (j + 1 > triangle[i].size()) ? INT_MAX : triangle[i][j] + dp[i + 1][j + 1];
			// move down
			int down = triangle[i][j] + dp[i + 1][j];
			// take minimum of both diag and down
			dp[i][j] = min(diag, down);
		}
	}
	// return the final answer
	return dp[0][0];
}