class Solution {
  // Recursion + Memoization Code
private:
  int f(int ind, vector<int> &height, vector<int> &dp) {
    // if the index is 0 or 1 then return 0
    if (ind == 0)
      return 0;
    if (dp[ind] != -1)
      return dp[ind];
    // make a jump from ind to ind-1 also add the absolute difference of heights
    // and solve for the remaining ind-1 indices
    int jump1 = abs(height[ind] - height[ind - 1]) + f(ind - 1, height, dp);
    // make a jump from ind to ind-2 also add the absolute difference of heights
    // and solve for the remaining ind-2 indices
    int jump2 = INT_MAX;
    // only make a jump to ind-2 if the index is more than 1 meaning there are more than 2 stairs
    if (ind > 1)
      jump2 = abs(height[ind] - height[ind - 2]) + f(ind - 2, height, dp);
    // take the minimum of the two jumps which takes less energy
    return dp[ind] = min(jump1, jump2);
  }
public:
  int minimumEnergy(vector<int>& height, int n) {
    // Code here
    // f(n) -> minimum energy required to from nth stair to 0th stair
    vector<int> dp(n + 1, -1);
    // Tabulation Code
    dp[0] = 0;
    for (int ind = 1; ind <= n; ind++) {
      int jump1 = abs(height[ind] - height[ind - 1]) + dp[ind - 1];
      // make a jump from ind to ind-2 also add the absolute difference of heights
      // and solve for the remaining ind-2 indices
      int jump2 = INT_MAX;
      if (ind > 1)
        jump2 = abs(height[ind] - height[ind - 2]) + dp[ind - 2];
      // take the minimum of the two jumps which takes less energy
      dp[ind] = min(jump1, jump2);
    }
    int prev1 = 0, prev2 = INT_MAX;
    // Space Optimization Code
    for (int ind = 1; ind < n; ind++) {
      int jump1 = abs(height[ind] - height[ind - 1]) + prev1;
      int jump2 = INT_MAX;
      if (ind > 1)
        jump2 = abs(height[ind] - height[ind - 2]) + prev2;
      int curr = min(jump1, jump2);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};