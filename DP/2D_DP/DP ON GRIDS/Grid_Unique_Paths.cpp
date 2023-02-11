// Problem Link:- https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
	// Write your code here.
	// dp(i,j) -> Number of ways to reach from the cell (i,j) to the cell (m-1,n-1)
	// final answer-> dp(0,0)
	// dp(i,j)=dp(i,j+1)+dp(i+1,j)
	// dp(m-1,n-1)=1

	int dp[m][n];
	// calculate for all (i,j) for all i ranging from (m-1 to 0) and for all j ranging from (n-1 to 0)
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// if the cell is (m-1,n-1) then there is only 1 way
			if (i == m - 1 && j == n - 1) {
				dp[i][j] = 1;
				continue;
			}
			else {
				//calculate the ways to go right and down from the cell (i,j)
				int right = (j + 1 == n) ? 0 : dp[i][j + 1];
				int down = (i + 1 == m) ? 0 : dp[i + 1][j];
				// and add the answers for both the ways to get the answer for cell (i,j)
				dp[i][j] = right + down;
			}
		}
	}
	// return the final answer stored at (0,0)
	return dp[0][0];
}