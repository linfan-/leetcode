/**
 * Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/ 
 * Author : linfan
 * Date   : 2015-02-06
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 *  For example:
 *      Given linked list: 1->2->3->4->5, and n = 2.
 *      After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Given n will always be valid.
 * Try to do this in one pass.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    /* 用两个相距n快慢指针，每次都走一步，当快指针到达尾部时候，慢指针指向的下一个节点就是需要删除的节点 */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n <= 0) {
            return NULL;
        }
        ListNode *slow, *fast, *deleteNode;
        int i;
        slow = fast = head;
        for (i = 1; i <= n; i++) {
             /* n是有效的，所以下面情况不会出现，但为了避免出现段错误加上 */
            if (!fast)
                return NULL;
            fast = fast->next;
        }
        /* 删除的是链表头部 */
        if (fast == NULL) {
            deleteNode = head;
            head = head->next;
        } else {
            while (fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            deleteNode = slow->next;
            slow->next = deleteNode->next;
        }
        free(deleteNode);
        return head;
    }
};
