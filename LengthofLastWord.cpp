/**
 * Source : https://oj.leetcode.com/problems/length-of-last-word/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * test case: "aaa  a   "
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0, i;
        bool hasSpace = false;
        if (s == NULL) {
            return length;
        }
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ') {
               hasSpace = true;
            } else {
                if (hasSpace) {
                    length = 1;
                    hasSpace = false;
                } else {
                    length++;
                }
            }
        }
        return length;
    }
};
