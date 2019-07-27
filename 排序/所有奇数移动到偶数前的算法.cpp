//
// Created by Newmor on 2019-09-22.
//

#include <cstdio>

#define ElemType int

//用于交换两个变量的函数
void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

void moveFigure(ElemType a[], int len) {
    //采用快速排序的partition的思想
    //从两端分别选取变量若是奇数则放到前面若是偶数则放到后面
    int left = 0;
    int right = len - 1;
    while (left < right) {
        //将right指向从右 往左数第一个奇数
        while (left < right && a[right] % 2 == 0) {
            right--;
        }
        //将left指向从左 往右数第一个偶数
        while (left < right && a[left] % 2 == 1) {
            left++;
        }
        if (left < right) {
            //交换left和right所指的元素
            swap(&a[left], &a[right]);
        }
    }
}

int main() {
    int a[10] = {1, 2, 4, 6, 7, 8, 9, 10, 5, 3};
    moveFigure(a, 10);

    //c++11推荐的遍历数据的方式 for in
    for (int x:a) {
        printf("%d\t", x);
    }
    return 0;
}