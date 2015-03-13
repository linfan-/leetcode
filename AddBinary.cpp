/**
 * Source : https://oj.leetcode.com/problems/add-binary/ 
 * Author : linfan
 * Date   : 2015-02-11
 *
 * Given two binary strings, return their sum (also a binary string).
 * For example,a = "11" b = "1"  Return "100".
 */

class Solution {
public:
    string addBinary(string a, string b) {
        /* 特殊处理，a或b为空 */
        if (a.size() == 0 && b.size() == 0) {
            return "0";
        } else if (a.size() == 0) {
            return b;
        } else if (b.size() == 0) {
            return a;
        }
        string sum;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int  extra = 0;
        stack<int> bit;
        while (i >= 0 && j >= 0) {
            if (a[i--] == '1') {
                extra++;
            } 
            if (b[j--] == '1') {
                extra++;
            }
            bit.push(extra%2);
            extra /= 2;
        }
        
        while (i >= 0) {
            if (a[i--] == '1') {
                extra++;
            }
            bit.push(extra%2);
            extra /= 2;
        }
        
         while (j >= 0) {
            if (b[j--] == '1') {
                extra++;
            }
            bit.push(extra%2);
            extra /= 2;
        }
        
        if (extra == 1) {
            bit.push(1);
        }
        
        while (!bit.empty()) {
            sum += bit.top() + '0';
            bit.pop();
        }
        
        return sum;
    }
};
