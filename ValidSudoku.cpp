/**
 * Source : https://oj.leetcode.com/problems/valid-sudoku/ 
 * Author : linfan
 * Date   : 2015-02-11
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

class Solution {
public:
    void setZero(int a[], int n) {
        int i;
        for (i = 0; i <= n; i++) {
            a[i] = 0;
        }
    }
    bool isHasDuplicateDigit(int a[], int n) {
         int i;
         for (i = 0; i <= n; i++) {
             if (a[i] > 1) {
                 return false;
             }
         }
         return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int num[10];
        int i, j, k, digit;
        /* 检查行 */
        for (i = 0; i < 9; i++) {
            setZero(num, 9);
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    digit = board[i][j] - '0';
                    num[digit]++;
                }
            }
            if (!isHasDuplicateDigit(num, 9)) {
                return false;
            }
        }
        /* 检查列 */
         for (i = 0; i < 9; i++) {
            setZero(num, 9);
            for (j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    digit = board[j][i] - '0';
                    num[digit]++;
                }
            }
            if (!isHasDuplicateDigit(num, 9)) {
                return false;
            }
        }
        /* 检查9个小区域 */
        for (i = 0; i < 9; i++) {
            setZero(num, 9);
            for (j = (i/3)*3; j <= (i/3)*3 + 2; j++) {
                for (k = (i%3)*3; k <= (i%3)*3 + 2; k++) {
                    if (board[j][k] != '.') {
                        digit = board[j][k] - '0';
                        num[digit]++;
                    }
                }
            }
            
            if (!isHasDuplicateDigit(num, 9)) {
                return false;
            }
        }
        
        return true;
    }
};
