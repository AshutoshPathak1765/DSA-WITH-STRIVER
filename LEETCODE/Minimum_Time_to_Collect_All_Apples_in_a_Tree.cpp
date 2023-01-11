/*
Problem Link:- https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
YT Link:- https://www.youtube.com/watch?v=Xdt5Z583auM
*/
class Solution {
private:
  // dfs function which return the minimum time needed to collect all apples
  int dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &hasApple, int node, int par) {
    // intitially timer will be initialized to 0
    int timer = 0;
    // mark current node as visited
    vis[node] = 1;
    // traverse over the adjacency list of current node
    for (int child : adj[node])
      // if the child is not visited call dfs on the subtree and calculate the minimum time to collect the apples in the subtree of the current node
      if (!vis[child])
        timer += dfs(adj, vis, hasApple, child, node);
// after the calculation of subtree we calculate the answer for the current node i.e the minimum time needed to
// collect apples rooted at this current node
    // if the current node has an apple and the current node is not root than we add 2 to the answer as it takes
    // 2 units of time to move between parent of the current node and the current node
    if (hasApple[node]) {
      if (par != -1)
        timer += 2;
    }
    // else if the current node doesn't have an apple than we check if the subtree of the current node had
    //apples or not if it had apples and also the current node is not root than we add 2 to the answer
    // as it takes 2 units of time between the child of the current node and the current node
    else if (timer > 0 && par != -1)
      timer += 2;
    // we repeat the above process for all the nodes of the tree calculate the answer for left subtree
    // and right subtree and using the answer of both subtrees calculate the answer for current node and move upwards in the tree
    // finally return the total minimum time
    return timer;
  }
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    // creating a adjacency list of size n
    vector<int> adj[n];
    // creating graph using the edges
    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    // intializing visited array of size n
    vector<bool> vis(n, 0);
    // calling the dfs function with node 0 and parent -1
    return dfs(adj, vis, hasApple, 0, -1);
  }
};