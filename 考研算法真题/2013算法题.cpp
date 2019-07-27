//
// Created by Newmor on 2019-10-14.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

/*
 *
 * 2013年算法题
 *
 *
 * 理解题意：统计数组重复元素个数，若有元素出现的次数>n/2则返回它，否则返回-1
 *
 * 个人思路：和2018年有些类似，种树法，与王道解答不同
 *
 * 1。新建一个长度为n的辅助数组assist，用于每个记录元素出现的个数
 * 2。遍历A数组，每出现一个元素则在assist数组中把以该数组元素值为下标的记录+1
 * 3。遍历assist数组，找到出现元素次数最多的元素，返回
 * 4。若出现次数>n/2,则返回该元素位于assist数组中的下标，否则返回-1
 *
 * 时间复杂度：O(n) 空间复杂度O（n) （王道的算法空间复杂度较好但是紧张时候可能想不到。
 * */

//寻找主元素，若找到则返回之，否则返回-1
int findMainElem(int A[], int n) {

    //建立一个数组长度岁n动态变化的初始值为0的辅助数组
    int *assist;//建立辅助数组的指针
    assist = (int *) malloc(sizeof(int) * n);//动态分配内存空间
    memset(assist, 0, sizeof(int) * n);//赋予初值0

    //遍历A 统计出现频率
    for (int i = 0; i < n; ++i) {
        assist[A[i]] += 1;//出现次数+1
    }
    int max = 0;//记录assist最大值
    int max_index = -1;//记录assist最大值的下标
    //遍历assist数组寻找最大值
    for (int i = 0; i < n; ++i) {
        if (assist[i] > max) {
            max = assist[i];
            max_index = i;
        }
    }
    //比较最大值是否>n/2 （这里隐含了向上取整）
    if (max > ceil(n / 2)) {
        return max_index;
    }

    return -1;
}

int main() {
    int A[8] = {0, 5, 5, 3, 5, 1, 5, 5};
    printf("主元素-->%d", findMainElem(A, 8));
    return 0;
}