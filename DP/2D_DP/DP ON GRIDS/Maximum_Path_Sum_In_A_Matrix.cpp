// Problem Link:- https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13
#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = INT_MIN;
    int dp[n][m];
    // dp(i,j) -> Maximum Sum that can be obtained from the cell (i,j) to the cell (n-1,x)
    // Final Answer-> max(dp(0,j)) for all j's from 0 to m-1
    // Recurrence -> dp(i,j)= max(matrix[i][j]+dp(i+1,j),matrix[i][j]+dp(i+1,j+1),matrix[i][j]+dp(i+1,j-1))
    // Base Case -> dp[n-1][j]=matrix[n-1][j] for all j's from 0 to m-1
    for (int j = 0; j < m; j++)
        dp[n - 1][j] = matrix[n - 1][j];
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int left_diag = (j >= 1) ? matrix[i][j] + dp[i + 1][j - 1] : INT_MIN;
            int right_diag = (j + 1 >= m) ? INT_MIN : matrix[i][j] + dp[i + 1][j + 1];
            int down = matrix[i][j] + dp[i + 1][j];
            dp[i][j] = max(left_diag, max(right_diag, down));
        }
    }
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[0][j]);
    return maxi;
}