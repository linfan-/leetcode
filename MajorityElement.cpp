/**
 * Source : https://oj.leetcode.com/problems/majority-element/ 
 * Author : linfan
 * Date   : 2015-02-05
 *
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 *
 */
class Solution {
public:
    /* 出现次数大于n/2，其个数必定比其它剩下的个数要多 */
    int majorityElement(vector<int> &num) {
        int times = 0, val;
        vector<int>::iterator it;
        
        for (it = num.begin(); it != num.end(); it++) {
            if (times == 0) {
                val = *it;
                times = 1;
            } else {
                times = (*it == val) ? times + 1 : times - 1;
            }
        }
        
        return val;
    }
};
