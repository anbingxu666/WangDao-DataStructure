//
// Created by HappyBing on 2020-01-26.
//

/*
 *
 *HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
 * 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
 * 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
 * 连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
 * */



#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int FindGreatestSumOfSubArray1(vector<int> array) {
    if (array.size() == 0) {
        return 0;
    }
    int total = array[0];
    int maxSum = array[0];//记录最大值
    for (int i = 1; i < array.size(); ++i) {//遍历整个数组
        if (total >= 0) {
            total += array[i];
        } else {
            total = array[i];
        }

        if (total > maxSum) {
            maxSum = total;
        }

    }
    return maxSum;

}



// 解法2 动态规划


int getMax(int a, int b)   //得到两个数的最大值
{
    return (a) > (b) ? (a) : (b);
}

int FindGreatestSumOfSubArray(vector<int> array) {
    if (array.size() == 0) {
        return 0;
    }

    int res = array[0];
    int max = array[0];
    for (int i = 1; i < array.size(); ++i) {
        max = getMax(max + array[i], array[i]);//核心 看加上之后变大 若还不如加的数字大则取加的数组作为遍历到i的和
        res = getMax(max, res);//取较大的作为最终结果
    }
    return res;
}