/**
 * Source : https://oj.leetcode.com/problems/excel-sheet-column-number/ 
 * Author : linfan
 * Date   : 2015-02-04
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 */

class Solution {
public:
    int titleToNumber(string s) {
        int i;
        int colnum = 0;
        for (i = 0; i < s.length(); i++) {
            colnum = 26 * colnum + (s[i] - 'A' + 1); 
        }
        return colnum;
    }
};
