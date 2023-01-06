class Solution {
public:
  // Function to return a list containing the DFS traversal of the graph.
  void dfs(int source, vector<int> adj[], bool *vis, vector<int> &res) {
    // mark source as visited
    vis[source] = 1;
    // add the source node to result vector
    res.push_back(source);
    // loop through all adjacent nodes of the given node
    for (int adjNode : adj[source])
      // if the adjacent node is not visited
      if (!vis[adjNode])
        // call dfs on adjacent node which is not adjacent node
        dfs(adjNode, adj, vis, res);
  }
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    // create a result vector to store dfs traversal
    vector<int> res;
    // create a visited array for the V vertices
    bool vis[V] = {0};
    // call dfs on node 0
    dfs(0, adj, vis, res);
    // return the final result vector
    return res;
  }
};