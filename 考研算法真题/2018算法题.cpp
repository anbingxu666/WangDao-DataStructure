//
// Created by  Newmor on 2019-10-12.
//

/*
 *
 * 2018年算法题
 *
 * 此题和leetcode某道题思想类似，采用 "种树法"
 * 此题怎么思路最重要，实现的话若给定数组数值范围不确定，则空间复杂度与具体算法实现有关，我的算法
 * 只能适用于给定的数在整数范围内。
 *
 * 思路：
 *
 * 1.新建一个辅助数组assist 长度为int的最大值2^31-1
 * 2。遍历整数数组，将得到值作为操作assist数组的下标，若该值大于0，则将对应下标元素赋值为1
 * 3。从1遍历assist数组 找到第一个为0的数组下标
 * 4。返回该下标
 *
 * 时间复杂度O(n) 空间复杂度为定值与n无关。
 *
 * */
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define INT_MAX 0x7fffffff

int findMinPosInt(int array[], int n) {
    //返回值为未出现的正整数
    //若返回-1 则代表无法找到

    int *assist = (int *) malloc(sizeof(int) * INT_MAX);//建立辅助数组
    memset(assist, 0, sizeof(int) * n);//将其初始化为0

    //遍历题目所给数组
    for (int i = 0; i < n; ++i) {
        if (array[i] > 0) {//保证数据是正整数的同时避免下标越界
            assist[array[i]] = 1;
        }
    }
    //遍历辅助数组
    for (int i = 1; i <= INT_MAX; ++i) {
        if (assist[i] == 0) {//找到第一个数值为0的下标
            return i;//返回
        }
    }
    return -1;//若不存在则返回-1
}

int main() {
    int array[3] = {1, -2, 13};
    printf("答案-->%d", findMinPosInt(array, 3));
}