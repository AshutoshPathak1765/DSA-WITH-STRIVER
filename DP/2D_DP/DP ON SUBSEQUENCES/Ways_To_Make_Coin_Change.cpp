// Problem Link:- https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // dp(i,s) -> Number of ways to make a sum s using the elements [0...i]
    // final answer-> dp(n-1,value)
    // Recurrence-> dp(i,s)=dp(i-1,s)+dp(i,s-denominations[i])
    // Base Case-> dp[0][0]=1
    // dp[0][s]=1 if s%denominations[0]==0 for all s from [0...value]

    long dp[n][value + 1];
    for (int i = 0; i < n; i++)
        for (int s = 0; s <= value; s++)
            dp[i][s] = 0;
    // Base Cases
    dp[0][0] = 1;
    for (int s = 0; s <= value; s++)
        if (s % denominations[0] == 0)
            dp[0][s] = 1;
    // Calculating the answer for the remaining array
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= value; s++) {
            long op1 = dp[i - 1][s];
            long op2 = (s >= denominations[i]) ? dp[i][s - denominations[i]] : 0;
            dp[i][s] = op1 + op2;
        }
    }
    // return the final answer
    return dp[n - 1][value];
}