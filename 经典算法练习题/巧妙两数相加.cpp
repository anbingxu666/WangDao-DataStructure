//
// Created by HappyBing on 2020-05-16.
//
/*
 * 两个二进制的相加结果是用一个异或门实现的；
   两个二进制的进位结果是用一个与门来实现的。
 *
 * */


#include <cstdio>

int Add(int num1, int num2) {
    int result, ans;
    do {
        result = num1 ^ num2;       // 每一位相加
        ans = (num1 & num2) << 1;   // 进位
        num1 = result;              // 记录几位相加的结果
        num2 = ans;                 // 记录还剩几位
    } while (ans != 0);
    return result;
}