/**
 * Source : https://oj.leetcode.com/problems/remove-element/ 
 * Author : linfan
 * Date   : 2015-02-10
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 */

class Solution {
public:
    /* 就地替换,找到第一个重复的位置，在此位置之前，元素不变，此位置之后，非此元素依次替换 */
    int removeElement(int A[], int n, int elem) {
        if (n == 0) {
            return 0;
        }
        int length = n, nextPos = -1;
        int i;
        for (i = 0; i < n; i++) {
            if (A[i] == elem) {
                if (nextPos == -1) {
                    nextPos = i;
                }
                length--;
            } else {
                if (nextPos != -1) {
                    A[nextPos++] = A[i];
                }
            }
        }
        
        return length;
    }
};
