/**
 * Source : https://oj.leetcode.com/problems/linked-list-cycle/ 
 * Author : linfan
 * Date   : 2015-02-05
 *
 * Given a linked list, determine if it has a cycle in it.
 * Can you solve it without using extra space?
 *
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *slow, *fast;
        slow = fast = head; /* 用快慢两个指针，慢指针一次移动一步，快指针一次移动二步，如果存在环，两指针必会相遇 */
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            } else {
                return false;
            }
            
            if (slow == fast) {
                return true;
            }
        } 
        return false;
    }
};
