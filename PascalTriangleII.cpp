/**
 * Source : https://oj.leetcode.com/problems/pascals-triangle-ii/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,Return [1,3,3,1].
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> ret;
        int i, j;
        for (i = 1; i <= rowIndex + 1; i++) {
            ret.push_back(1);
        }   
        for (i = 3; i <= rowIndex + 1; i++) {
             /* 首尾1不变 */
            for (j = i - 2; j >= 1; j--) {
                ret[j] = ret[j] + ret[j-1];
            }
        }   
        return ret;
    }
};
