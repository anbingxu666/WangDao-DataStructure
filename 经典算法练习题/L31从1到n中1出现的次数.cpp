//
// Created by HappyBing on 2020-05-29.
//
#include <iostream>
#include <vector>

using namespace std;

int NumberOf1Between1AndN_Solution(int n) {
    if (!n) return 0;
    //n >= 1
    vector<int> num;
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }

    int res = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int left = 0, right = 0, x = 1;
        //高位到低位 left
        for (int j = num.size() - 1; j > i; j--)
          //计算低位 right
        for (int k = i - 1; k >= 0; k--) {
            right = right * 10 + num[k];
            x *= 10;
        }

        //计算位数
        res = res + left * x;
        if (num[i] == 1) res += right + 1; //若第i位出现了1 ，则因为第i位为1 1的个数增加了right + 1个
        else if (num[i] > 1) res += x;// 若第i为出现2-9 ，则第i位对1个数的影响是前面个数

    }
    return res;
}