/*
Problem Link:- https://leetcode.com/problems/non-decreasing-subsequences/description/
YT Link:- https://www.youtube.com/watch?v=xmxqGG97Bx4
*/

/*
Approach:- We use a backtracking approach where we take into consideration at any particular index ind whether this element will be part of the subsequence or not.If this element is part our of subsequence we insert it into our vector that maintains the current subsequence till now.After we have processed all the indexes and our index ind reaches the end of our input array(nums.size()) we have a subsequence which we would like to examine whether it is a increasing subsequence of length >=2 or not so and also this subsequence must be increasing in nature(i.e.there should not be any element in the subsequence such that it is smaller than the previous element in the same subsequence) and also we must only add the subsequence to our answer 2D vector only if this subsequence is not already inserted to our 2D vector for that we maintain a set which checks for duplicate subsequence and does not allow duplicate subsequence to be inserted in our 2D answer vector.
*/

/*
Defintion of Valid Subsequence:- a subsequence is valid if it satisfies the following three conditions enumerated below:-

1. Subsequence must be of length atleast 2.
2. Subsequence must be increasing in nature (there should not exist any index i in the subsequence such that element at index i is less than element at index i-1).
3.Subsequence must be unique (i.e. same valid subsequence must not be counted more than once in our answer).
*/
class Solution {
private:
    // function to check if the current subsequence (present in ds vector) is increasing as well as is of size >=2 and also unique(i.e. this subsequence has not been previously inserted in our 2D answer vector)
    bool ValidSubsequence(vector<int> &ds, set<vector<int>> &unique) {
        if (ds.size() < 2 || (unique.find(ds) != unique.end()))
            return false;
        for (int i = 1; i < ds.size(); i++)
            if (ds[i] < ds[i - 1])
                return false;
        return true;
    }
    // function which generates all the possible subsequences of the input array
    void findSubsequences(int ind, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, set<vector<int>> &unique) {
        // if our input array is exhausted
        if (ind == nums.size()) {
            // we check if the subsequence is valid or not (valid-> subsequence must be of size>=2 and is increasing in nature and must also be unique(not already inserted in our 2D answer vector))
            if (ValidSubsequence(ds, unique)) {
                // if its valid then insert this subsequence to our 2D answer vector
                ans.push_back(ds);
                // insert this subsequence to our set
                unique.insert(ds);
            }
            return;
        }
        // we consider the element at index ind to be a part of our subsequence
        ds.push_back(nums[ind]);
        // we compute all subsequences such that element at index ind is always considered to be part of subsequence
        findSubsequences(ind + 1, nums, ans, ds, unique);
        // backtracking step we remove the element at index ind from the subsequence
        ds.pop_back();
        // we compute all subsequence such that element at index ind is never considered to be part of subsequence
        findSubsequences(ind + 1, nums, ans, ds, unique);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // a 2D answer vector to store all valid subsequences
        vector<vector<int>> ans;
        // a vector that stores one subsequence at a time
        vector<int> ds;
        // a set which is used to eliminate duplicates of same valid subsequence in our answer.
        set<vector<int>> unique;
        // compute all valid subsequences
        findSubsequences(0, nums, ans, ds, unique);
        // return the final valid subsequences thus calculated
        return ans;
    }
};