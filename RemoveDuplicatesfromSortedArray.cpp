/**
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/ 
 * Author : linfan
 * Date   : 2015-02-10
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 */
class Solution {
public:
    /* 时间复杂度为O(n^2)做法,超时了 */
    int removeDuplicatesTimeExceeded(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int length = n;
        int i, j;
        int val = A[n-1];
        for (i = n - 2; i >= 0; i--) {
            if (val == A[i]) {
                for (j = i; j <= length - 2; j++) {
                    A[j] = A[j+1];
                }
                length--;
            } else {
                val = A[i];
            }
        }
        
        return length;
    }
    
     int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int length = n;
        int i, j;
        int nextPos = -1;
        int val = A[0];
        
        for (i = 1; i < n; i++) {
            if (val == A[i]) {
                if (nextPos == -1) {
                    nextPos = i;
                }
                
                length--;
            } else {
                if (nextPos != -1) {
                    A[nextPos++] = A[i];
                }
                val = A[i];
            }
        }
        return length;
     }
};
