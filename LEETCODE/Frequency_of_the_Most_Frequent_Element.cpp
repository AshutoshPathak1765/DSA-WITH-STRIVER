/*
Problem Link:- https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
YT Link:- https://www.youtube.com/watch?v=vgBrQ0NM5vE&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=7
*/
// Approach:- sort+sliding window
// 1.we must convert only those elements that are closest to a given element as it take less increment operations
// 2.also the elements greater than a given element must not be converted as they are greater than or equal to
// to our given element and we have only increment operations and not decrement operations.Hence we sort our input arrays to get closest elements to our given element efficiently and then apply a sliding window on our array to calculate the number of elements that we can convert to an element at index r such that all elements from [l...r]
// are same and element at index r has the maximum frequency.We repeat this process for all our possible windows
// and return the maximum frequency we can get out of all possible windows.
class Solution {
private:
    // good method which tells that our current window from [l....r] is good or not
    // good means that whether all the elements in our current window can be converted to the element at index r
    // using atmost k number of increment operations or not
    bool good(long long total, int k, int r, int l, vector<int> &nums) {
        int windowLength = r - l + 1;
        long long val = nums[r] * 1LL * windowLength;
        return val <= total + k;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        // intializing left and right pointers for sliding window
        int l = 0, r = 0, n = nums.size();
        // a total variable to maintain the sum of elements in the current window
        long long total = 0;
        // variable to store the max frequency
        int maxFreq = 0;
        // sort our input array in increasing order
        sort(nums.begin(), nums.end());
        // iterate over our input array
        while (r < n) {
            // add the value at the current index to our total
            total += nums[r];
            // while the window in consideration does not satisfy the constraint remove the value from
            // the left end of the window from total and also increment the left pointer of our window
            while (!good(total, k, r, l, nums)) {
                total -= nums[l];
                l++;
            }
            // after the loop is executed our current window is good and we take the length of the good window
            int windowLength = r - l + 1;
            // update the max frequency accordingly
            maxFreq = max(maxFreq, windowLength);
            // increment the right pointer of our window
            r++;
        }
        // return the max frequency
        return maxFreq;
    }
};