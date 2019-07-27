//
// Created by newLion on 2020-06-05.
//

#include <iostream>>
bool dfs(char *matrix, int rows, int cols, int i, int j, bool *flag, char *str);
bool hasPath(char *matrix, int rows, int cols, char *str) {
    bool res = 0;
    bool *flag = new bool[rows * cols];
    memset(flag, 0, rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //bool *flag = (bool *)calloc(rows*cols, 1);
            res = dfs(matrix, rows, cols, i, j, flag, str);//1
            if (res)
                return res;
        }
    }
    delete[] flag;
    return res;
}

bool dfs(char *matrix, int rows, int cols, int i, int j, bool *flag, char *str) {
    if (*str == '\0')
        return true;
    if (i < 0 || i >= rows || j < 0 || j >= cols) // 越界了
        return false;
    if (*(flag + i * cols + j) == 1 || (*(flag + i * cols + j) == 0 && *(matrix + i * cols + j) != *str))
        return false;
    else {
        *(flag + i * cols + j) = 1; //已访问
        bool res = dfs(matrix, rows, cols, i, j - 1, flag, str + 1)//左
                   || dfs(matrix, rows, cols, i, j + 1, flag, str + 1)//右
                   || dfs(matrix, rows, cols, i - 1, j, flag, str + 1)//上
                   || dfs(matrix, rows, cols, i + 1, j, flag, str + 1);//下
        if (res == 0)
            *(flag + i * cols + j) = 0;//这样从1处开始进入的DFS即使没找到路径，但是flag最后全部置为0
        return res;
    }
}