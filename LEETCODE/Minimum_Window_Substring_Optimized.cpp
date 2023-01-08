/*
Problem Link:- https://leetcode.com/problems/minimum-window-substring/description/
YT Link:- https://www.youtube.com/watch?v=jSto0O4AJbM&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=3
*/
class Solution {
    // Approach:- Consider a window of size of length of string t initially then check if the current window satisy
    // the condition that all the characters of string t are present in string s if the condition is satisfied we reduce the left pointer of window while the condition is satisfied and store the left pointer and minLen of the string we do this process for all possible windows and take the minimum window that contains all the characters of string t
private:
    // check if the two hashmaps satisfy the condition or not
    bool good(unordered_map<char, int> &sCount, unordered_map<char, int> &tCount) {
        for (auto it : tCount) {
            char ch = it.first;
            if ((sCount.find(ch) == sCount.end()) || (sCount[ch] < tCount[ch]))
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        // if the size of string s is less than size of string t then return ""
        if (s.size() < t.size())
            return "";
        // create an empty string result
        string result = "";
        // create two hashmaps for the string s and string t to store frequency of individual characters in the
        // respective strings respectively
        unordered_map<char, int> sCount, tCount;
        int n = s.size(), m = t.size();
        // insert the characters of string t into tCount hashmap
        for (int i = 0; i < m; i++)
            tCount[t[i]]++;
        // intialize left pointer of the building a minLen variable to store minimum length of the substring
        // and also a left variable to store the left pointer of the window containing the minimum window substring
        int l = 0, minLen = INT_MAX, left = -1;
        // iterate over the string s
        for (int r = 0; r < n; r++) {
            // if the length of window is less than the size of the string t than simply add the character to
            // the sCount hashmap and continue to the next iteration
            if (r - l + 1 < m) {
                // add the current character to the window to the sCount hashmap only if its occurs in the tCount hashamap
                if (tCount.find(s[r]) != tCount.end())
                    sCount[s[r]]++;
                continue;
            }
            // add the current character to the window to the sCount hashmap only if it occurs in the tCount hashmap
            if (tCount.find(s[r]) != tCount.end())
                sCount[s[r]]++;
            // while the condition is satisfied
            while (good(sCount, tCount)) {
                // if the length of window is less than min length so far
                if (r - l + 1 < minLen) {
                    // update the minimum length
                    minLen = r - l + 1;
                    // and store the left pointer of the current window to our left variable
                    left = l;
                }
                // remove the character from the window and reduce the count from the sCount hashmap
                sCount[s[l]]--;
                // if the count of character removed from window becomes 0 then remove it from the sCount hashmap
                if (sCount[s[l]] == 0)
                    sCount.erase(s[l]);
                // shift the window to the right
                l++;
            }
        }
        // after the entire string is traversed if we find a valid window we retrieve the substring using
        // left pointer and the minLen variable
        if (left != -1)
            result = s.substr(left, minLen);
        // finally return the result string
        return result;
    }
};

