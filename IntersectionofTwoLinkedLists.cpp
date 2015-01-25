/**
 * Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists/ 
 * Author : linfan
 * Date   : 2015-02-06
 *
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * Notes:
 *      If the two linked lists have no intersection at all, return null.
 *      The linked lists must retain their original structure after the function returns.
 *      You may assume there are no cycles anywhere in the entire linked structure.
 *      Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        ListNode *p1, *p2;
        int lengthA = 0, lengthB = 0, i, dis;
        /* 遍历链表，得到链表的长度 */
        for (p1 = headA; p1 != NULL; p1 = p1->next) {
            lengthA++;
        }
        for (p1 = headB; p1 != NULL; p1 = p1->next) {
            lengthB++;
        }
        /* 让比较长的链表先走|lengthA-lengthB|步 */
        if (lengthA > lengthB) {
            p1 = headA;
            p2 = headB;
            dis = lengthA - lengthB;
        } else {
            p1 = headB;
            p2 = headA;
            dis = lengthB - lengthA;
        }
        for (i = 1; i <= dis; i++) {
            p1 = p1->next;
        }
        /* 此时两链表一样长，同时向前移动，如果有交点，必定相等 */
        while (p1 && p2) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        /* 没有交点 */
        return NULL;
        
    }
};
