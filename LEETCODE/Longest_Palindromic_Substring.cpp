/*
Problem link:-https://leetcode.com/problems/longest-palindromic-substring/
YT Link :- https://www.youtube.com/watch?v=XYQecbcd6_c&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=7
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        string ans;
        int n = s.size();
        // Approach:- Consider each index of the string as the middle character
        // of a palindrome extend to both the left and right side to check the
        // longest length of palindrome by considering the character at index
        // i as the middle character of the palindrome
        for (int i = 0; i < n; i++) {
            // odd length palindromes
            // start with middle character
            int l = i, r = i;
            // extend to both sides of the string while it is a palindrome
            while (l >= 0 && r < n && s[l] == s[r]) {
                // if the current length of palindrome is greater than already
                // calculated result
                if (resLen < r - l + 1) {
                    // update the current length of palindrome to  new length
                    resLen = r - l + 1;
                    // store the substring s[l...r+1] in our answer
                    ans = s.substr(l, r - l + 1);
                }
                // extending the substring from both sides
                l--, r++;
            }
        }
        // above approach works for odd length palindromes so we run another
        // time with a slight modification to check for even length palindromes
        // even length palindromes
        for (int i = 0; i < n; i++) {
            // slight modification here
            int l = i, r = i + 1;
            // same as the above step for odd length palindrome
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (resLen < r - l + 1) {
                    resLen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
                // extend the string to both sides
                l--;
                r++;
            }
        }
        // return the final answer string
        return ans;
    }
};