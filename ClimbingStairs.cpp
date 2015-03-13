/**
 * Source : https://oj.leetcode.com/problems/climbing-stairs/ 
 * Author : linfan
 * Date   : 2015-02-11
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
public:
    /* A(n) = A(n-1) + A(n-2) */
    int climbStairs(int n) {
        /* n = 0，1，2 */
        if (n <= 2) {
            return n;
        }
        int i;
        int ways[n + 1];
        ways[1] = 1;
        ways[2] = 2;
        for (i = 3; i <= n; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        
        return ways[n];
    }
};
