//
// Created by Newmor on 2019-10-23.
//


#include <cstdio>

/*
 * 此问题相当于将数组的元素逆序问题的升级版
 *
 * 解法1：最优解
 * 思想：若循环左移动p位，则在p的位置将数组分为两部分
 *  将左边的一部分逆序
 *  将有边的一部分逆序
 *  最后将整个数组逆序
 *  时间复杂度：O(n)
 *  空间复杂度：O(1)
 *
 *
 *  解法2：暴力算法
 *  复制出一个数组，直接分成两部分，将左边的部分放到右边。右边的部分放到左边
 *  时间复杂度：O(n)
 *  空间复杂度:O(n)
 * */

void reverse(int a[], int left, int right) {
    int i, j;
    for (i = left, j = right; i <= j; ++i, --j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void moveP(int a[], int n, int p) {
    reverse(a, 0, p - 1);
    reverse(a, p, n - 1);
    reverse(a, 0, n - 1);
}

int main() {
    int a[5] = {0, 1, 2, 3, 4};
    moveP(a, 5, 2);

    //我偷懒六用的for-in遍历 c不支持 请使用下标遍历
    for (int x : a) {
        printf("%d\t", x);
    }

    return 0;
}