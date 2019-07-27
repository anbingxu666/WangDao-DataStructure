//
// Created by HappyBing on 2020-01-12.
//
#include <cstdio>
#include <cmath>
double Power(double base, int exponent) {
    //递归出口
    if (exponent == 0) {//特殊情况1
        return 1;
    }
    if (exponent == 1) {//特殊情况2
        return base;
    }
    //递归函数
    double result = Power(base, exponent >> 1);
    result *= result;//乘方递归体
    if (exponent & 0x1 == 1) {//判断奇偶次方
        result *= base;
    }
    return result;
}
//int main(){
//    printf("%lf",pow(2.0,-1.0));
//}