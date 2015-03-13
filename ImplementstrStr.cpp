/**
 * Source : https://oj.leetcode.com/problems/implement-strstr/ 
 * Author : linfan
 * Date   : 2015-02-11
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

class Solution {
public:
    /* 普通做法，算法复杂度 O(M*N) */
    int strStrTimeLimitExceeded(char *haystack, char *needle) {
        if (!haystack || !needle) {
            return -1;
        }
        int i, j, k;
        
        for (i = 0; haystack[i] != '\0'; i++) {
            j = i;
            k = 0;
            while (haystack[j] != '\0' && needle[k] != '\0' && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (needle[k] == '\0') {
                return i;
            }
        }
        
        return -1;
    }
    /* next[j] */
    void nextJ(int next[], int len, char *s) {
        int k = -1;
        int j = 0;
        next[0] = -1;
        while (j < len) {
            if (k == -1 || s[j] == s[k]) {
                k++;
                next[++j] = k;
            } else {
                k = next[k];
            }
        }
    }
    /* KMP算法 */
     int strStr(char *haystack, char *needle) {
         if (!haystack || !needle) {
            return -1;
        }
        int needleLen = 0, haystackLen = 0;
        while (needle[needleLen] != '\0') {
            needleLen++;
        }
        while (haystack[haystackLen] != '\0') {
            haystackLen++;
        }
        int next[needleLen];
        nextJ(next, needleLen, needle);
        int i = 0, j = 0;
        while (i < haystackLen && j < needleLen) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == needleLen) {
            return i - j;
        }
        return -1;
        
     }
};
