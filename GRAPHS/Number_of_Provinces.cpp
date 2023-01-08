//User function Template for C++

class Solution {
public:
  // standard dfs function that accepts the source node ,the adjacency list representation
  // of the graph and bool visited array to keep track of the visited nodes in our graph.
  void dfs(int u, vector<int> adj[], bool *vis) {
    vis[u] = 1;
    for (int v : adj[u])
      if (!vis[v])
        dfs(v, adj, vis);
  }
  int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    vector<int> ar[V + 1];
    // creating a boolean visited array and setting it to false for all nodes.
    bool vis[V + 1];
    for (int i = 0; i <= V; i++)
      vis[i] = 0;
    // converting adjacency matrix representation of graph to an adjacency list representation.
    for (int i = 0; i < adj.size(); i++)
      for (int j = 0; j < adj[i].size(); j++)
        if (adj[i][j] && i != j)
          ar[i + 1].push_back(j + 1);
    //variable for storing the number of connected components.
    int res = 0;
    // apply dfs for each component seperately and also incrementing the result when a new component is encountered.
    for (int i = 1; i <= V; i++)
      if (!vis[i]) {
        dfs(i, ar, vis);
        res++;
      }
    // returning the final result.
    return res;
  }
};