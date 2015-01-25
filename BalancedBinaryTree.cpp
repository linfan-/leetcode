/**
 * Source : https://oj.leetcode.com/problems/balanced-binary-tree/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    int getDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        int diff = (leftDepth > rightDepth) ? leftDepth - rightDepth : rightDepth - leftDepth;
        if (diff > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
};
