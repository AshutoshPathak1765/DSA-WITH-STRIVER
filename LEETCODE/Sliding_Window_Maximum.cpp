/*
 Problem Link:- https://leetcode.com/problems/sliding-window-maximum/description/
 YT Link:- https://www.youtube.com/watch?v=DfljaUwZsOk&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=6
*/
class Solution {
    // Approach:- Use the concept of monotonic decreasing queue where the queue is sorted in decreasing order
    // such that the left most value of the queue is the maximum of our window
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // create an empty deque which stores indices
        deque<int> dq;
        // intitalize left pointer
        int l = 0, n = nums.size();
        // intialize result vector
        vector<int> result;
        // iterate over the array
        for (int r = 0; r < n; r++) {
            // pop values from the rightmost side of the queue until the rightmost value is greater than or equal to nums[r]
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();
            // insert the index of the current element at index r
            dq.push_back(r);
            // if the left pointer goes out of bound of the deque remove it
            if (l > dq.at(0))
                dq.pop_front();
            // if the size of the window is atleast k
            if (r - l + 1 >= k) {
                // take the left most value from the deque and insert it to our result
                result.push_back(nums[dq.front()]);
                // increment the left pointer and shift the window to the right
                l++;
            }
        }
        // return the result vector
        return result;
    }
};