/**
 * Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        queue<TreeNode*> q1, q2, *qPtr, *tmpPtr;
        TreeNode *cur;
        if (!root) {
            return ret;
        }
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            vector<int> levelRet; 
            qPtr = q1.empty() ? &q2 : &q1;
            tmpPtr = q1.empty() ? &q1 : &q2;
            while (!qPtr->empty()) {
                cur = qPtr->front();
                qPtr->pop();
                levelRet.push_back(cur->val);
                if (cur->left) {
                    tmpPtr->push(cur->left);
                }
                if (cur->right) {
                    tmpPtr->push(cur->right);
                }
            }
            ret.push_back(levelRet);
            
        }
        return ret;
        
    }
};
