/**
 * Source : https://oj.leetcode.com/problems/string-to-integer-atoi/ 
 * Author : linfan
 * Date   : 2015-02-12
 *
 * Implement atoi to convert a string to an integer.
 */
int myAtoi(char *str) {
    if (!str) {
        return 0;
    }
    long v = 0;
    int minus = 1;
    int i = 0;
    /* 去掉前置空格 */
    while (str[i] != '\0' && isspace(str[i])) {
        i++;
    }
    /* 处理 +/- */
    if (str[i] == '-') { 
        minus = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    /* 计算，遇到非数字，直接跳出 */
    while (str[i] != '\0' && isdigit(str[i])) {
        v = v * 10 + str[i] - '0';
        i++;
        /* 处理溢出情况 */
        if (v * minus >= INT_MAX) {
            return INT_MAX;
        }
        if (v * minus <= INT_MIN) {
            return INT_MIN;
        }
    }
    return v * minus;
}
