/**
 * Source : https://oj.leetcode.com/problems/merge-sorted-array/ 
 * Author : linfan
 * Date   : 2015-02-10
 *
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
class Solution {
public:
    /* 与合并有序链表类似，从m+n-1位开始填 */
    void merge(int A[], int m, int B[], int n) {
        int i, j, k;
        i = m - 1;
        j = n -1;
        k = m + n - 1;
        while (i >= 0 && j >= 0 )  {
            if (A[i] >= B[j]) {
                A[k--] = A[i];
                i--;
            } else {
                A[k--] = B[j];
                j--;
            }
        }
        while (i >= 0) {
            A[k--] = A[i--];
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};
