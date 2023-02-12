// Problem Link:- https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18
#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	// dp(i,s) -> check if it's possible to make a sum of s using the array [0...i]
	// final answer-> minimum difference mini over all valid sums from [0...sum(arr)]
	// a valid sum means the sum that can be created using some elements from the array
	// Recurrence-> dp(i,s)=dp(i-1,s)||dp(i-1,s-arr[i])
	// Base Case-> dp(i,0)= true for all i from [0..n-1]
	// dp(0,arr[0])=true if arr[0]<=sum where sum is the sum of the array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	bool dp[n][sum + 1];

	for (int i = 0; i < n; i++)
		for (int s = 0; s <= sum; s++)
			dp[i][s] = false;
	// dp(i,0)=true for all i from [0...n-1]
	for (int i = 0; i < n; i++)
		dp[i][0] = true;
	// dp(0,arr[0])=true if arr[0]<=sum
	if (arr[0] <= sum)
		dp[0][arr[0]] = true;
	// calculating the answer for all the remaining array
	for (int i = 1; i < n; i++) {
		for (int s = 0; s <= sum; s++) {
			bool op1 = dp[i - 1][s];
			bool op2 = (s >= arr[i]) ? dp[i - 1][s - arr[i]] : false;
			dp[i][s] = (op1 || op2);
		}
	}
	int mini = 1e8;
	// finding the minimum absolute difference over all valid sums of the entire array
	for (int s = 0; s <= sum; s++)
		if (dp[n - 1][s] && dp[n - 1][abs(s - sum)])
			mini = min(mini, abs(2 * s - sum));
	// return the minimum absolute difference
	return mini;
}
