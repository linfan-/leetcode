/**
 * Source : https://oj.leetcode.com/problems/single-number/ 
 * Author : linfan
 * Date   : 2015-02-04
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int i;
        int singleNumber = 0;
        for (i = 0; i < n; i++) {
            singleNumber ^= A[i];
        } 
        return singleNumber;
    }
};
