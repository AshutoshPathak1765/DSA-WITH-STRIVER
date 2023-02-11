// Problem Link:- https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11
#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    // dp(i,j) -> minimum sum from the cell (i,j) to the cell (n-1,m-1)
    // final answer-> dp(0,0)
    // Recurrence-> dp(i,j)= min(grid[i][j]+dp(i+1,j),grid[i][j]+dp(i,j+1))
    // Base Case-> dp(n-1,m-1)=grid[n-1][m-1]
    int dp[n][m];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = grid[i][j];
                continue;
            }
            else {
                int right = (j + 1 == m) ? INT_MAX : grid[i][j] + dp[i][j + 1];
                int down = (i + 1 == n) ? INT_MAX : grid[i][j] + dp[i + 1][j];
                dp[i][j] = min(right, down);
            }
        }
    }
    return dp[0][0];
}