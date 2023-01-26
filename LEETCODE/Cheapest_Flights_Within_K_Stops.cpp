/*
Problem Link:- https://leetcode.com/problems/cheapest-flights-within-k-stops/
YT Link:- https://www.youtube.com/watch?v=9XybHVqTHcQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=37
*/

/*
Approach:- Applying djikstra's algorithm where we would be minimizing the number of stops instead of the price
since we must reach the destination using at most k stops therefore it is important to minimize the number of stops
used we may encounter a path which may take cheapest price but it may have more than k stops which violates our condition of using
at most k stops.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creating an adjacency list of the form {node,price}
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v, price});
        }
        // creating a cost array to store the cost of reaching any node i from a source src
        vector<int> cost(n, INT_MAX);
        // {stops,{price,node}}
        // creating a minimum priority queue of the form {stops,{price,node}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // pushing the source node to our priority queue
        pq.push({0, {0, src}});
        // set cost for source as 0
        cost[src] = 0;
        // initialize minimum price variable for the price ot reach from source to destination
        int mini_price = INT_MAX;
        // using standard djikstra's algorithm
        while (!pq.empty()) {
            // take out the topmost element from the priority queue
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int price = it.second.first;
            int node = it.second.second;
            // if the current node is our destination then take the minimum price with already computed minimum price
            if (node == dst)
                mini_price = min(mini_price, cost[node]);
            // go to all adjacent of the current node
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int adjPrice = it.second;
                // if the stops used till now are less than or equal to k
                if (stops <= k) {
                    // check if the price to reach adjNode is less than already computed value for adjNode
                    if (price + adjPrice < cost[adjNode]) {
                        // update cost to reach adjNode
                        cost[adjNode] = price + adjPrice;
                        // push the adjNode to our priority queue
                        pq.push({1 + stops, {cost[adjNode], adjNode}});
                    }
                }
            }
        }
        // if the minimum price is INT_MAX return -1 else return the minimum price
        return (mini_price == INT_MAX ? -1 : mini_price);
    }
};