/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
   Problem Link:- https://leetcode.com/problems/binary-tree-preorder-traversal/description/
   YT Link:- https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=38
*/

// Using Morris Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // initialize cur to root;
        TreeNode *cur = root;
        // traverse while cur is not NULL
        while (cur != NULL) {
            // if left doesn't exist then simply insert the node's value to the vector and move to the right.
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // move to the rightmost node of the left subtree until we reach NULL or reach the same node cur again via the thread we created
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                // if the right is NULL create the thread such that prev->right points to the cur node as well as insert the cur node's value to the vector and move to the left.
                if (!prev->right) {
                    prev->right = cur;
                    res.push_back(cur->val);
                    cur = cur->left;
                }
                else {
                    // disconnect the thread and move to the right
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        // return the final answer.
        return res;
    }
};