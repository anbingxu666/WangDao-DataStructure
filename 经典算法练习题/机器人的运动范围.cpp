//
// Created by newLion on 2020-06-06.
//
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int digit_sum(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> flag(rows, vector<bool>(cols));
        int b = dfs(threshold, rows, cols, 0, 0, flag);
        return b;

    }

    int dfs(int threshold, int rows, int cols, int i, int j, vector<vector<bool>> &flag) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || (digit_sum(i) + digit_sum(j)) > threshold ||
            flag[i][j]) {//访问越界
            return 0;
        }
        flag[i][j] = true;
        return 1 + dfs(threshold, rows, cols, i - 1, j, flag) +
               dfs(threshold, rows, cols, i + 1, j, flag) +
               dfs(threshold, rows, cols, i, j - 1, flag) +
               dfs(threshold, rows, cols, i, j + 1, flag);
    }
};