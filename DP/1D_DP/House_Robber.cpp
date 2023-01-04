class Solution
{
// Recursion + Memoization Code
private:
  int f(int ind, int *arr, vector<int> &dp) {
    // if there is only one element we take that element as maximum
    if (ind == 0)
      return arr[0];
    if (ind < 0)
      return 0;
    if (dp[ind] != -1)
      return dp[ind];
    int take = INT_MIN, notTake = INT_MIN;
    // take the loot from index
    take = arr[ind] + f(ind - 2, arr, dp);
    // else don't take the loot from ind
    notTake = f(ind - 1, arr, dp);
    // return the maximum of the two results
    return dp[ind] = max(take, notTake);
  }
public:
  // calculate the maximum sum with out adjacent
  int FindMaxSum(int *arr, int n) {
    // code here
    // f(n) -> maximum sum from house n to house 1 without taking adjacent elements
    // Corner case when there are only two houses we return the maximum loot from two houses
    // out of the two elements
    if (n == 2)
      return max(arr[0], arr[1]);
    // Tabulation Code
    vector<int> dp(n + 1, -1);
    dp[0] = arr[0];
    for (int ind = 1; ind < n; ind++) {
      int take = INT_MIN, notTake = INT_MIN;
      // take the element from index if ind-2 exists
      if (ind > 1)
        take = arr[ind] + dp[ind - 2];
      else
        // else don't take the ind-2 element
        take = arr[ind];
      // else don't take the element from ind
      notTake = dp[ind - 1];
      // return the maximum of the two results
      dp[ind] = max(take, notTake);
    }
    // Space Optimization Code
    int prev1 = arr[0], prev2 = 0;
    for (int ind = 1; ind < n; ind++) {
      int take = INT_MIN, notTake = INT_MIN;
      // take the loot from index
      take = arr[ind] + prev2;
      // else don't take the element from ind
      notTake = prev1;
      // return the maximum of the two results
      int curr = max(take, notTake);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};