/**
 * Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/ 
 * Author : linfan
 * Date   : 2015-02-05
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) {
            return NULL;
        } else if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        }
        
        ListNode *l, *p, *p1, *p2;
        if (l1->val < l2->val) {
            l = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            l = l2;
            p2 = l2->next;
            p1 = l1;
        }
        p = l;
        p->next = NULL;
        
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
            p->next = NULL;
        }
        
        if (p1) {
            p->next = p1;
        } else if (p2) {
            p->next = p2;
        }
        
        return l;
    }
};
