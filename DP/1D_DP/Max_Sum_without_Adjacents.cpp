//User function template for C++
class Solution {
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
    // take the element from index
    take = arr[ind] + f(ind - 2, arr, dp);
    // else don't take the element from ind
    notTake = f(ind - 1, arr, dp);
    // return the maximum of the two results
    return dp[ind] = max(take, notTake);
  }
public:
  // calculate the maximum sum with out adjacent
  int findMaxSum(int *arr, int n) {
    // code here
    // f(n) -> maximum sum from index n to index 1 without taking adjacent elements
    // Corner case when there are only two elements we return the maximum element
    // out of the two elements
    if (n == 2)
      return max(arr[0], arr[1]);
    // Tabulation Code
    vector<int> dp(n + 1, -1);
    dp[0] = arr[0];
    for (int ind = 1; ind < n; ind++) {
      int take = INT_MIN, notTake = INT_MIN;
      // take the element from index
      if (ind > 1)
        take = arr[ind] + dp[ind - 2];
      else
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
      // take the element from index
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