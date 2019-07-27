//
// Created by HappyBing on 2020-05-13.
//
/* 求1+2+3+...+n
 * 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/


#include <cstdio>

int Sum_Solution(int n) {
    int sum = n;
    sum && (sum += Sum_Solution(--n));
    return sum;
}

// 算法思想:递归+短路&&计算.思路和下面的代码一样。利用逻辑与运算符的短路实现if0 return0
int f(int n) {
    if (n == 0) {
        return 0;
    }
    return n + f(n - 1);
}