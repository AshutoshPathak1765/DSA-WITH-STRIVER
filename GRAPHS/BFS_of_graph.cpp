class Solution {
private:
    vector<int> bfs(int source, vector<bool> &vis, vector<int> adj[]) {
        // queue for bfs traversal
        queue<int> q;
        // push the source node to the queue
        q.push(source);
        // mark the source node as visited
        vis[source] = 1;
        vector<int> res;
        // while the queue is not empty
        while (!q.empty()) {
            // take out the front node from queue
            int node = q.front();
            // mark it as visited
            // push the current node to the result vector
            res.push_back(node);
            // pop the front node from the queue
            q.pop();
            // loop through all the adjacent nodes for the current node
            for (int adjNode : adj[node]) {
                // if the given adjNode is not visited add it to the queue
                if (!vis[adjNode]) {
                    q.push(adjNode);
                    // mark the adjNode as visited
                    vis[adjNode] = 1;
                }
            }
        }
        // return the resultant vector containing bfs traversal
        return res;
    }
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // intitalize a visited array of size V
        vector<bool> vis(V, 0);
        // answer vector to store bfs
        vector<int> ans;
        // call bfs on the 0th vertex
        ans = bfs(0, vis, adj);
        // return the answer vector
        return ans;
    }
};