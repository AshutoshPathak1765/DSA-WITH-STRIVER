/*
Problem Link:- https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
YT Link:- https://www.youtube.com/watch?v=AZA8orksO4w
*/

/*
Approach:- Apply djikstra's algorithm for nodes node1 and node2 and then check for all the nodes which are reachable from the both nodes then take the node which has the minimum maximum distance from both nodes node1 and node2
*/
class Solution {
private:
    // standard djikstra's algorithm
    vector<int> djikstra(vector<int> adj[], int n, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        pq.push({0, src});
        distance[src] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            for (int adjNode : adj[node]) {
                if (1 + dist < distance[adjNode]) {
                    distance[adjNode] = 1 + dist;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        // converting edges into graphs
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        // getting the shortest path for each node from node 1 and node 2 using djikstra's algorithm
        vector<int> dist1 = djikstra(adj, n, node1);
        vector<int> dist2 = djikstra(adj, n, node2);
        // variables for minimum distance and for storing node value respectively
        int mini = INT_MAX, node = -1;
        // iterate over all nodes of the graph
        for (int i = 0; i < n; i++) {
            //if a node i is not reachable from either node1 or node2 then simply continue
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX)
                continue;
            else {
                // otherwise take the maximum distance from both the node1 and node2 respectively
                int dist = max(dist1[i], dist2[i]);
                // if the distance is less than already calculated distance then update the distance and update the node value
                if (dist < mini) {
                    mini = dist;
                    node = i;
                }
            }
        }
        // finally return the answer node
        return node;
    }
};