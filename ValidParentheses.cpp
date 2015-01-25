/**
 * Source : https://oj.leetcode.com/problems/valid-parentheses/ 
 * Author : linfan
 * Date   : 2015-02-06
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i;
        char topChar;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                topChar = st.top();
                st.pop();
                if ((s[i] == ')' && topChar != '(') ||
                    (s[i] == '}' && topChar != '{') || 
                    (s[i] == ']' && topChar != '[')) {
                        return false;
                    }
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
