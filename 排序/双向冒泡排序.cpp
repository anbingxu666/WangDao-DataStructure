//
// Created by Newmor on 2019-09-22.
//


#include <cstdio>

#define ElemType int

void swap(int *, int *);

//双向冒泡排序算法
void BubbleSort(ElemType a[], int n) {
    int left = 0;
    int right = n - 1;//left 和right代表待排序部分的左右边界
    int flag = true;//用于优化冒泡排序的flag
    while (left < right && flag) {
        flag = false;//置标志为
        //从左向右边冒泡排序
        for (int i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                flag = true;
            }
        }
        right--;//最高部分每排好一个元素右边界减1

        for (int i = right; i > left; --i) {
            if (a[i] < a[i - 1]) {
                swap(&a[i], &a[i - 1]);
                flag = true;
            }
        }
        left++;//最低部分每排好一个元素左边界加1

    }
}

//用于交换两个变量的函数
void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

int main() {
    int a[10] = {-99, -666, 40000, 000, 2, 1, -1001, 12, -14, 7};//数组有序元素10个下标从1-9
    BubbleSort(a, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d\t", a[i]);
    }
    return 0;
}