/**
 * Source : https://oj.leetcode.com/problems/valid-palindrome/ 
 * Author : linfan
 * Date   : 2015-02-12
 *
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 */

class Solution {
public:
    bool isAlphaNumeric(char c) {
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ) {
                return true;
            }
        return false;
    }
    bool isEqual(char c1, char c2) {
        if (toupper(c1) == toupper(c2)) {
            return true;
        } else {
            return false;
        }
    }
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int i, j;
        i = 0;
        j = s.size() - 1;
        
        while (i < j) { /* i != j is wrong*/
            if (!isAlphaNumeric(s[i])) {
                i++;
            } else if (!isAlphaNumeric(s[j])) {
                j--;
            } else if (isEqual(s[i], s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
