/*
 Problem Link:- https://leetcode.com/problems/find-all-anagrams-in-a-string/
 YT Link:- https://www.youtube.com/watch?v=G8xtZy0fDKg&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=5
*/

class Solution {
    // Approach:- Maintain two hashmaps for the two strings and maintain a window of size of the string p
    // now check for the current window if its a anagram of the string p or not if it is a anagram then
    // insert the left boundary of the window to our result vector and slide the window to the right while
    // removing the character of the lth index and inserting the character of the rth index and repeating the process for the entire string
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> sCount, pCount;
        int n = s.size(), m = p.size();
        for (int i = 0; i < m; i++)
            pCount[p[i]]++;
        int l = 0;
        vector<int> result;
        for (int r = 0; r < n; r++) {
            // check both hashmaps if they are equal or not
            if (r - l + 1 < m) {
                sCount[s[r]]++;
                continue;
            }
            sCount[s[r]]++;
            auto it = pCount.begin();
            bool found = true;
            while (it != pCount.end()) {
                char ch = it->first;
                if ((sCount.find(ch) == sCount.end()) || (sCount[ch] != pCount[ch])) {
                    found = false;
                    break;
                }
                it++;
            }
            // if the two hashmaps are equal then insert the left boundary index of the window to the result
            if (found)
                result.push_back(l);
            // decrease the frequency of the character at index l
            sCount[s[l]]--;
            // if the frequency becomes 0 than remove the character from the hashmap
            if (sCount[s[l]] == 0)
                sCount.erase(s[l]);
            // shift the window to the right
            l++;
        }
        // return the final result vector
        return result;
    }
};