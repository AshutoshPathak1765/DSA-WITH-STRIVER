class Solution {
private:
    // Recursion + Memoization Code
    int f(int ind, int k, vector<int> &height, vector<int> &dp) {
        // if the step is 0 return 0
        if (ind == 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        // initialize minimum ans to +INF
        int mini = INT_MAX;
        // make a jump from ind to ind-i where i varies from 1 to k
        for (int i = 1; i <= k; i++) {
            int jump = INT_MAX;
            // make a jump only if there are stones to jump on and take absolute difference
            // of heights and solve for the remaining stones
            if (ind >= i)
                jump = abs(height[ind] - height[ind - i]) + f(ind - i, k, height, dp);
            // take the minimum energy consumed among all jumps
            mini = min(mini, jump);
        }
        return dp[ind] = mini;
    }
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        // f(n) -> minimum cost to reach from step n-1 to step 0
        vector<int> dp(n, -1);
        // Tabulation Code
        dp[0] = 0;
        for (int ind = 1; ind < n; ind++) {
            int mini = INT_MAX;
            for (int i = 1; i <= k; i++) {
                int jump = INT_MAX;
                // make a jump only if there are stones to jump on and take absolute difference
                // of heights and solve for the remaining stones
                if (ind >= i)
                    jump = abs(height[ind] - height[ind - i]) + dp[ind - i];
                // take the minimum energy consumed among all jumps
                mini = min(mini, jump);
            }
            dp[ind] = mini;
        }
        return dp[n - 1];
    }
};