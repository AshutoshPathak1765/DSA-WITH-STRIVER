class Solution
{
private:
    // Recursion + Memoization Code
    int f(int ind, const int mod, vector<int> &dp) {
        // if we are at the ground step or at the first step the number of ways is 1
        if (ind == 0 || ind == 1)
            return 1;
        if (dp[ind] != -1)
            return dp[ind];
        // else we take either 1 step or 2 step and calculate the number of ways to reach from
        // to go from n-1 to 1 and from n-2 to 1
        return dp[ind] = (f(ind - 1, mod, dp) % mod + f(ind - 2, mod, dp) % mod) % mod;
    }
public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        const int mod = 1e9 + 7;
        // f(n) -> return number of ways to go from step n to step 1
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;
        //Tabulation Code

        for (int ind = 2; ind <= n; ind++)
            dp[ind] = (dp[ind - 1] % mod + dp[ind - 2] % mod) % mod;
        // return dp[n];

        // Space Optimization Code
        int prev1 = 1, prev2 = 1;
        for (int ind = 2; ind <= n; ind++) {
            int curri = (prev1 % mod + prev2 % mod) % mod;
            prev1 = prev2;
            prev2 = curri;
        }
        return prev2;
    }
};
