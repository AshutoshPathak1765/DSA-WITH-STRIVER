/*
 Problem Link:- https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
 YT Link:- https://www.youtube.com/watch?v=dw79Uf4s3cA
*/
class Solution {
  /* Approach:- We consider for every index i the prefix from 0 to i-1 is already monotonic increasing in nature.
  now there arise two cases:-

  Case 1:- The character at index i is a one then we don't need to do anyflips for index i as the prefix from 0
  to i-1 is already monotonic increasing(according to our initial condition for each index) and appending a one to the end of a monotonic sequence still makes the sequence as monotonic increasing therefore there is no change in the answer therefore in this step we only count the number of ones and don't make any changes to the answer as the answer remains unchanged for this case.

  Case 2:- The character at index i is a zero then in order to make the sequence monotonic increasing we convert this zero to one or we change ones present in the prefix 0 to i-1 to all zeros in order to make the sequence monotonic increasing till index i. Since we need the minimum flips to do so we take the minimum of the two steps
  i.e. ans=min(ans+1,one) such that ans is the previous answer for the prefix from 0 to i-1 which is already monotonic increasing we add a +1 to the previous answer or we convert all the ones to all zeros from the prefix 0 to i-1 which is equal to count of ones from the prefix 0 to i-1 in order to make the prefix from 0 to i as a monotonic increasing sequence.
  */
public:
  int minFlipsMonoIncr(string s) {
    // an answer variable which stores the answer for the minimum flips required to make the prefix from 0 to i-1
    // as monotonic increasing sequence and a variable one which counts the number of ones present in the prefix from 0 to i-1.
    int ans = 0, n = s.size(), one = 0;
    // iterate over the input string
    for (int i = 0; i < n; i++)
      // if the character at index i is a one then simply increment the count of one as the current sequence after adding the one to the previous monotonic increasing sequence from 0 to i-1 also results in a monotonic increasing sequence
      if (s[i] == '1')
        one++;
      else
        // if the character at index i is a zero then simply check the minimum for the count of ones for the prefix 0 to i-1 and also for changing the character from zero to one which changes the answer to answer+1
        ans = min(ans + 1, one);
    // return the final number of flips
    return ans;
  }
};