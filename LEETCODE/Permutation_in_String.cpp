/*
    Problem Link:- https://leetcode.com/problems/permutation-in-string/
    YT Link:- https://www.youtube.com/watch?v=UbyhOgBN834&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=9
*/
class Solution {
    // Approach:- Maintain two hashmaps for the two strings and maintain a window of size of the string s
    // now check for the current window if it is a permutation of string s then we return true else we slide the window to the right while removing the character at index l and adding the character at index r. If after traversing the entire string p we didn't find a permutation of string s than we return false
public:
    bool checkInclusion(string s, string p) {
        unordered_map<char, int> sCount, pCount;
        int n = s.size(), m = p.size();
        for (int i = 0; i < n; i++)
            sCount[s[i]]++;
        int l = 0;
        for (int r = 0; r < m; r++) {
            if (r - l + 1 < n) {
                pCount[p[r]]++;
                continue;
            }
            pCount[p[r]]++;
            // check if two hashmaps are equal
            auto it = sCount.begin();
            bool found = true;
            while (it != sCount.end()) {
                char ch = it->first;
                if ((pCount.find(ch) == pCount.end()) || (sCount[ch] != pCount[ch])) {
                    found = false;
                    break;
                }
                it++;
            }
            // if the two hashmaps are equal then we have found a permutation of string s and hence we return true
            if (found)
                return true;
            // decrease the frequency of the character at index l
            pCount[p[l]]--;
            // if the frequency becomes 0 than remove the character from the hashmap
            if (pCount[p[l]] == 0)
                pCount.erase(p[l]);
            // shift the window to the right
            l++;
        }
        // else if we didn't find the permutation in the entire string we return false
        return false;
    }
};