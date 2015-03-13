/**
 * Source : https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/ 
 * Author : linfan
 * Date   : 2015-02-09
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) {
            return ret;
        }
        stack<vector<int> > s;
        queue<TreeNode*> q1, q2, *emptyQueue, *curQueue;
        TreeNode *cur;
        
        q1.push(root);
        
        while (!q1.empty() || !q2.empty()) {
            if (q1.empty()) {
                emptyQueue = &q1;
                curQueue = &q2;
            } else if (q2.empty()) {
                emptyQueue = &q2;
                curQueue = &q1;
            }
            vector<int> levelRet;
            while (!curQueue->empty()) {
                cur = curQueue->front();
                curQueue->pop();
                levelRet.push_back(cur->val);
                if (cur->left) {
                    emptyQueue->push(cur->left);
                }
                if (cur->right) {
                    emptyQueue->push(cur->right);
                }
            }
            s.push(levelRet);
        }
        
        while(!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }
};
