/**
 * Source : https://oj.leetcode.com/problems/symmetric-tree/ 
 * Author : linfan
 * Date   : 2015-02-09
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).)
 * For example, this binary tree is symmetric:
 *
 *     1
      / \
     2   2
    / \ / \
   3  4 4  3
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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmetricByIterative(root->left, root->right);
    }
    /* 本质上是判断左子树是否和右子树一样 */
    bool isSymmetricByRecursive(TreeNode *leftChild, TreeNode *rightChild) {
        if (!leftChild && !rightChild) {
            return true;
        } else if (leftChild && rightChild && leftChild->val == rightChild->val) {
            return isSymmetricByRecursive(leftChild->left, rightChild->right) 
                    && isSymmetricByRecursive(leftChild->right, rightChild->left);
        } else {
            return false;
        }
    }
    
    bool isSymmetricByIterative(TreeNode *root1, TreeNode *root2) {
        queue<TreeNode*> q1, q2;
        TreeNode *node1, *node2;
        q1.push(root1);
        q2.push(root2);
        while (!q1.empty() || !q2.empty()) {
            node1 = q1.front();
            node2 = q2.front();
            q1.pop();
            q2.pop();
            
            if (!node1 && !node2) {
                ;
            } else if (node1 && node2 && node1->val == node2->val) {
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);

            } else {
                return false;
            }
        }
        return true;
    }
};
