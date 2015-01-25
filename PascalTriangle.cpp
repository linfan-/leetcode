/**
 * Source : https://oj.leetcode.com/problems/pascals-triangle/ 
 * Author : linfan
 * Date   : 2015-02-08
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * For example, given numRows = 5,Return
 * [
        [1],
        [1,1],
        [1,2,1],
        [1,3,3,1],
        [1,4,6,4,1]
 * ] 
 *
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ret;
    int i, j;
    for (i = 0; i < numRows; i++) {
        vector<int> row;
        row.push_back(1);
    
        for (j = 1; j <= i - 1 ; j++) {
            row.push_back(ret[i-1][j-1] + ret[i-1][j]);
        }
        if (i != 0) {
            row.push_back(1);
        }
        ret.push_back(row);
    }   
    return ret;
    }
};
