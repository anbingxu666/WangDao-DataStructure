//
// Created by HappyBing on 2020-01-12.
//

#include <cstdio>
#define MAX 0x7FFFFFFF
#define MIN 0x10000000
using namespace std;

int NumberOf1(int n) {
    int count = 0;
    int flag = 1;
    while (flag) {//最多只会移动32次 左移是逻辑左移 （去掉最高位 右侧补0）
        if (flag & n) {
            ++count;
        }
        flag = flag << 1;
    }

    return count;
}
//
//int main() {
//    printf("%d\n",MIN);
//    printf("-->%d", NumberOf1(MIN));
//}