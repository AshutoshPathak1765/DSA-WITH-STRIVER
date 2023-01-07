/*
Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
YT Link:- https://www.youtube.com/watch?v=1pkOgXD63yU&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=1
*/
class Solution {
public:
    // Approach:- buy at less price sell at more price
    int maxProfit(vector<int>& prices) {
        int l = 0;
        // l -> buy
        // we buy at index l and sell at index r
        int n = prices.size();
        int maxProfit = 0;
        // r-> sell
        // iterate over prices for the n days
        for (int r = 0; r < n; r++) {
            // if we encounter any profit
            if (prices[l] < prices[r])
                // we check if this profit is more than our already calculated profit and update accordingly
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            else
                // otherwise this price at index r is less than the price at index l therefore we must buy at index r
                // instead of index l to save money which was needed to buy at a higher price earlier
                l = r;
        }
        // return the Maximum Profit thus calculated
        return maxProfit;
    }
};