/*
Problem Link:- https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

// Approach:- Use dp on trees which calculates the answer for the children then using the answer of the child nodes
// calculate the answer for the parent node and move upwards in the tree
class Solution {
private:
    // a function to return the number mapped to an alphabet like a->0,b->1,c->2 and so on.
    int charToInt(char ch) {
        return (ch - 'a');
    }
    // a dfs function to calculate the answer for the given node
    void dfs(int node, string &labels, vector<int> adj[], vector<vector<int>> &dp, vector<bool> &vis) {
        // mark current node as visited
        vis[node] = 1;
        // traverse over the adjacency list of current node
        for (int child : adj[node])
            // if the child is not visited
            if (!vis[child]) {
                // call dfs on the child
                dfs(child, labels, adj, dp, vis);
                // using the answer of the child node calculate the answer for the parent node
                for (int i = 0; i < 26; i++)
                    dp[node][i] += dp[child][i];
            }
        // increment the label count for the current node
        dp[node][charToInt(labels[node])]++;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // create a adjacency list using the edges
        vector<int> adj[n];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // create a 2D dp array of size n*26
        vector<vector<int>> dp(n, vector<int>(26, 0));
        // create a visited array of size n
        vector<bool> vis(n, 0);
        // call dfs on node 0
        dfs(0, labels, adj, dp, vis);
        // create an answer array to store the answer for all nodes
        vector<int> ans(n);
        // iterate on the nodes and store the answer for the current node stored at dp[i][label[i]-'a']
        for (int i = 0; i < n; i++)
            ans[i] = dp[i][charToInt(labels[i])];
        // return the answer array
        return ans;
    }
};