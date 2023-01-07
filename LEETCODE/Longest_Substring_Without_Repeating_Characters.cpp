/*
Problem Link:- https://leetcode.com/problems/longest-substring-without-repeating-characters/
YT Link:- https://www.youtube.com/watch?v=wiGpQwVHdE0&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=2
*/
class Solution {
    // Approach:- Use a dynamic sized sliding window and check if the substring inside the window has no repeating
    // characters then update the length of the longest length substring and slide the window
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, n = s.size();
        int maxLen = 0;
        // hashset to check for duplicates in the current window in O(1) time
        unordered_set<char> charSet;
        // iterate over the characters of the string
        for (int r = 0; r < n; r++) {
            // while there is a duplicate character in the window we shrink the window until there are no duplicate
            // characters in our window
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            // now the window contains only unique characters so we check the length of the window and
            // if the length is greater than already computed length we update our maximum length
            if (maxLen < r - l + 1)
                maxLen = r - l + 1;
            // now slide the window to the right and add the character at index r to the hashset
            charSet.insert(s[r]);
        }
        // return the maximum calculated length
        return maxLen;
    }
};