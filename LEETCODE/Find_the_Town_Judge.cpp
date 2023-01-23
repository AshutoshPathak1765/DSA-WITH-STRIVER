/*
Problem Link:- https://leetcode.com/problems/find-the-town-judge/description/
YT Link:- https://www.youtube.com/watch?v=fv5DlTbIbkA
*/
/*
Approach:- Create a adjacency list of trusts such that an edge between node u to node v denotes that for the person u trusts the person v.Therefore according to condition of the problem,the node u must be empty (as the judges trusts no one also this judge must be present in all the other nodes except the judge node as the judge is trusted by everyone).Therefore we simply simulate the above condition by building a graph and then finding the judge(node having no adjacent node) and after that we check for other nodes except the judge node whether this node is present in the adjacency list of all the other nodes.If the judge node is present in all the other nodes except judge than we have found the judge node else we don't have any judge and we return -1.
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // creating the adjacency lists of trusts
        vector<int> trusts[n + 1];
        for (auto it : trust) {
            // the trust edges are directed edges
            int u = it[0];
            int v = it[1];
            trusts[u].push_back(v);
        }
        // finding the judge node by checking the condition that the judge node doesn't have any adjacent node
        int judge = -1;
        for (int person = 1; person <= n; person++)
            if (trusts[person].size() == 0)
                judge = person;
        // after we have found out the potential judge node we check whether this node is present in the adjacency list of other nodes (except judge node) if we have this node in adjacency list of all the other nodes(except judge node) then this node is the judge node else we don't have any judge node and we return -1.
        for (int person = 1; person <= n; person++) {
            if (person != judge) {
                bool found = false;
                for (int trust : trusts[person]) {
                    if (trust == judge) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    judge = -1;
                    break;
                }
            }
        }
        // return the judge thus found.
        return judge;
    }
};