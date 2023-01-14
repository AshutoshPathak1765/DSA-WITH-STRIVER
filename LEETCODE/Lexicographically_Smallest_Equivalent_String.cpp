/*
Problem Link:- https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
*/

// Approach :- Use a disjoint set union data structure to group the alphabets which are equivalent according to the two strings s1 and s2 after that call the getminimum method for each character of the baseStr string and get the minimum character in each group to make the lexicographic smallest string
struct dsu {
    vector<int> parent, size, minimum, maximum;

    dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        minimum.resize(n + 1);
        maximum.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            maximum[i] = i;
            minimum[i] = i;
        }
    }

    int get(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = get(parent[a]);
    }

    void unite(int a, int b) {
        int ulpar_a = get(a);
        int ulpar_b = get(b);
        if (ulpar_a == ulpar_b)
            return;
        if (size[ulpar_a] > size[ulpar_b]) {
            parent[ulpar_b] = ulpar_a;
            size[ulpar_a] += size[ulpar_b];
            minimum[ulpar_a] = min(minimum[ulpar_a], minimum[ulpar_b]);
            maximum[ulpar_a] = max(maximum[ulpar_a], maximum[ulpar_b]);
        }
        else  {
            parent[ulpar_a] = ulpar_b;
            size[ulpar_b] += size[ulpar_a];
            minimum[ulpar_b] = min(minimum[ulpar_a], minimum[ulpar_b]);
            maximum[ulpar_b] = max(maximum[ulpar_a], maximum[ulpar_b]);
        }
    }

    int getMinimum(int a) {
        int par_a = get(a);
        return minimum[par_a];
    }

    int getMaximum(int a) {
        int par_a = get(a);
        return maximum[par_a];
    }
    int getSize(int a) {
        int par_a = get(a);
        return size[par_a];
    }
};

class Solution {
private:
    // get the integer assosiated to each character like a->0,b->1,c->2 and so on.
    int charToInt(char ch) {
        return (ch - 'a');
    }
    // get the character assosiated to each number like 97->a,98->b,99->c and so on.
    char intToChar(int i) {
        return char(97 + i);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        // create a disjoint set of size 26 same as the alphabet size of lower case english letters
        dsu ds(26);
        // group the assosiation of the both string using disjoint set data structure
        for (int i = 0; i < n; i++)
            ds.unite(charToInt(s1[i]), charToInt(s2[i]));
        // create an empty answer string
        string ans = "";
        int m = baseStr.size();
        // traverse over the baseStr string
        for (int i = 0; i < m; i++)
            // get the minimum character of the group of which baseStr[i] is a part of inorder to get smallest lexicographic string
            ans += intToChar(ds.getMinimum(charToInt(baseStr[i])));
        // return the answer string
        return ans;
    }
};