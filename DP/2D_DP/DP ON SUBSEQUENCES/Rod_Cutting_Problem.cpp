// Problem Link:- https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=mO8XpGoJwuo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=25
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// dp(i,l)-> maximum cost to cut the rod of length i such that we can form l
	// final answer-> dp(n-1,n)
	// dp(i,l)=max(dp(i-1,l),price[i]+dp(i,l-i-1))
	// Base Case-> dp(0,l)=l*price[0] for all l from [0...n]
	int dp[n][n + 1];
	// Base Case
	for (int l = 0; l <= n; l++)
		dp[0][l] = l * price[0];
	// Calculating the answer for remaining array
	for (int i = 1; i < n; i++) {
		for (int l = 0; l <= n; l++) {
			int op1 = dp[i - 1][l];
			int op2 = (l >= i + 1) ? price[i] + dp[i][l - (i + 1)] : 0;
			dp[i][l] = max(op1, op2);
		}
	}
	// return the final answer
	return dp[n - 1][n];
}
