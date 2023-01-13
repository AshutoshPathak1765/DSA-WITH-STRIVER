/*
Problem Link:- https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
*/
class Solution {
    // dfs function which takes a node,adjacency list,string and a reference variable ans and return the longest path of different adjacent characters of a node
    int dfs(int node, vector<int> adj[], string &s, int &ans) {
        // calculate the longest and second longest chain of different characters
        int longest = 0, secondlongest = 0;
        // traverse over the adjacency list of the node
        for (int child : adj[node]) {
            // call dfs on the child to get the longest chain of different adjacent characters
            int dist = dfs(child, adj, s, ans);
            // if the node and child do not have the same character
            if (s[child] != s[node]) {
                // then calculate the maximum and second maximum of the chain of different adjacent characters of a child node
                if (longest < dist) {
                    secondlongest = longest;
                    longest = dist;
                }
                else if (secondlongest < dist)
                    secondlongest = dist;
            }
        }
        // finally update the answer of the current node as the longest chains of the any two child nodes with +1 for the current node so longest+secondlongest+1 and take the maximum over all such nodes
        ans = max(ans, longest + secondlongest + 1);
        // return the longest path of the node of different adjacent characters
        return longest + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        // create the graph using the parent array
        vector<int> adj[n];
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
        // intialize the answer as 1
        int ans = 1;
        // call dfs on node 0
        dfs(0, adj, s, ans);
        // return the answer
        return ans;
    }
};