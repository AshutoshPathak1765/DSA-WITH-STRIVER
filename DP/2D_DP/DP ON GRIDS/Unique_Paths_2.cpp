// Problem Link:- https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    int dp[n][m];
    // dp(i,j) -> Number of ways to reach from cell (i,j) to the cell (n-1,m-1)
    // final answer-> dp(0,0)
    //Recurrence->
    //  dp(i,j)=0 ,if cell(i,j) has an obstacle
    // dp(i,j)=dp(i+1,j)+dp(i,j+1) ,if cell (i,j) does not have an obstacle
    // Base Case->
    // dp(n-1)(m-1)=1,if cell (n-1,m-1) does not have an obstacle
    // dp(n-1)(m-1)=0,if cell (n-1,m-1) has an obstacle
    const int mod = 1e9 + 7;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = (mat[i][j] != -1) ? 1 : 0;
                continue;
            }
            else {
                int right = (j + 1 == m || mat[i][j + 1] == -1) ? 0 : dp[i][j + 1];
                int down = (i + 1 == n || mat[i + 1][j] == -1) ? 0 : dp[i + 1][j];
                dp[i][j] = (right + down) % mod;
            }
        }
    }
    return dp[0][0];
}