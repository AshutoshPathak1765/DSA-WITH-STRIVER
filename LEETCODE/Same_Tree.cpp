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
   Problem Link:- https://leetcode.com/problems/same-tree/
   YT Link:- https://www.youtube.com/watch?v=BhuvF_-PWS0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=19
*/

class Solution {
    // Approach:- Apply any traversal on the tree and check if the left subtree and right subtree fulfill the
    // condition after that check if the root also fulfills the conditions if all the three conditions satisfy
    // we return a true else we return a false.
public:
    // used a preorder traversal but any traversal can work here
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check if both the trees are null simulataneously then only return true else return false
        if (p == NULL || q == NULL)
            return p == q;
        // if the value of root is not same then return false as the trees are not same
        if (p->val != q->val)
            return false;
        // call for the left and right subtree and return true if both the subtrees return true else return false
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};