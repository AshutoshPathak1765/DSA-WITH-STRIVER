/*
Problem Link:-https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
YT Link:- https://www.youtube.com/watch?v=ufXxc8Vty9A
*/

/*
Approach:- We use the concept of number of subarrays with sum 0 using hashmap and prefix sum to solve this problem.
We maintain a running sum to calculate the prefix sum till index i and then take the remainder of the running sum with the value k now we maintain a hashmap to store the count of all remainders from 0 to k-1. If while iterating we encounter a remainder which is already present in our map then increment the answer by the frequency of that remainder such that the remainder is the key in the map and the value is the number of times this remainder occured in our array. If this remainder does not exist in our map at any index i this means this is the first time this remainder occured so we put this remainder in our map with its frequency as 1. We must take special attention that the running sum can be negative so modulo operator may cause some discrepancy while calculating remainders
there in order to calculate the modulo k of some negative number we first take modulo of negative number and store it in a variable remainder than if the remainder is negative we add k to it to make the remainder value between 0 to k-1.We keep processing all the elements in our array and repeat the above algorithm and finally return our answer.
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // a variable n to store the size of nums array
        int n = nums.size();
        // a hashmap to store the count of remainders in our array where remainder is the key and the value is the number of times this remainder occured in our array
        unordered_map<int, int> rem_count;
        // two variables answer and running sum to store the final answer and for storing the prefix sum till index i respectively.
        int ans = 0, running_sum = 0;
        for (int i = 0; i < n; i++) {
            // Add this element to our running sum
            running_sum += nums[i];
            // take the remainder of this running sum with k
            int rem_val = running_sum % k;
            // if this remainder is negative we add k to the remaider to make the remainder between 0 to k-1
            if (rem_val < 0)
                rem_val += k;
            // if the remainder of any prefix of our array is 0 we add one to our answer as we encounter a subarray from 0 to a index i hence we increment our answer by one
            if (rem_val == 0)
                ans++;
            // if the remainder value does not exist in our hashmap then we add this remainder value with a frequency 1 in our hashmap
            if (rem_count.count(rem_val) == 0)
                rem_count.insert({rem_val, 1});
            else {
                // otherwise we add the number of times this remainder occured previously in our array to our answer
                ans += rem_count[rem_val];
                // also increment the remainder count for the current index
                rem_count[rem_val]++;
            }
        }
        // return the total number of subarrays which are divisible by k
        return ans;
    }
};