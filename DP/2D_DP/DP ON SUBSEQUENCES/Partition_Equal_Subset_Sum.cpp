// Problem Link:- https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	// dp(i,s)-> check if it's possible to make a sum s using the array [0...i]
	// Recurrence-> dp(i,s)=dp(i-1,s)||dp(i-1,s-arr[i]) (Here,|| represents the logical or operator)
	// Base Case-> dp(i,0)=true
	// if sum is odd return false
	// if(arr[0]<=sum) dp[0][arr[0]]=true
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	// if sum is odd return false
	if (sum & 1)
		return false;

	bool dp[n][sum + 1];

	for (int i = 0; i < n; i++)
		for (int s = 0; s <= sum; s++)
			dp[i][s] = false;
	// dp(i,0)=true
	for (int i = 0; i < n; i++)
		dp[i][0] = true;
	// dp[0][arr[0]]=true,if arr[0]<=sum
	if (arr[0] <= sum)
		dp[0][arr[0]] = true;
	// calculate for all remaining array
	for (int i = 1; i < n; i++) {
		for (int s = 0; s <= sum / 2; s++) {
			bool op1 = dp[i - 1][s];
			bool op2 = (s >= arr[i]) ? dp[i - 1][s - arr[i]] : false;
			dp[i][s] = (op1 || op2);
		}
	}
	// return the final answer
	return dp[n - 1][sum / 2];
}
