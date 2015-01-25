/**
 * Source : https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
       
        if (!root->left && !root->right) {  /* 叶子节点，返回1 */
            return 1;
        } else if (root->left && !root->right) { /* 只有左子树，计算左子树最低高度 */
            return 1 + minDepth(root->left);
        } else if (!root->left && root->right) { /* 只有右子树，计算左右树最低高度 */
            return 1 + minDepth(root->right);
        } else { /* 左右子树都有，取最低 */
            int leftDepth = minDepth(root->left);
            int rightDepth = minDepth(root->right);
        
            return (leftDepth > rightDepth) ? rightDepth + 1 : leftDepth + 1;
        }
       
    }
};
