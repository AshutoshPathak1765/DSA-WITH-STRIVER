// Problem Link:- https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// YT Link:- https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	// Write your code here
	// dp(i,W)-> maximum weight of items from the array from [0...i] if maximum allowed weight is W
	// final answer-> dp(n-1,maxWeight)
	// Recurrence-> dp(i,W)=max(dp(i-1,W),value[i]+dp(i-1,W-weight[i])) for all valid i
	// Valid i is an index where weight[i]>=W
	// Base Case-> dp(i,0)=0

	int prev[maxWeight + 1];
	for (int W = 0; W <= maxWeight; W++)
		prev[W] = 0;

	for (int wt = weight[0]; wt <= maxWeight; wt++)
		prev[wt] = value[0];

	for (int i = 1; i < n; i++) {
		for (int W = maxWeight; W >= 0; W--) {
			int op1 = prev[W];
			int op2 = (W >= weight[i]) ? value[i] + prev[W - weight[i]] : 0;
			prev[W] = max(op1, op2);
		}
	}
	return prev[maxWeight];
}