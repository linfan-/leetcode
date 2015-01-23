/**
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/ 
 * Author : linfan
 * Date   : 2015-02-04
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *pre, *cur;
        int val = head->val;
        pre = head;
        cur = head->next;
        
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                free(cur);
                cur = pre->next;
            } else {
                val = cur->val;
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
