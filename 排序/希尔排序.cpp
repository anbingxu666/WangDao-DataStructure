//
// Created by Newmor on 2019-09-18.
//

#include <cstdio>

//希尔排序：数组下标从1开始，a[0]存放的元素无效，默认升序
// 1 1 1 1 1 1 1 1 1 1
void shellSort(int a[], int len) {
    int j, i, dk;
    for (dk = len / 2; dk >= 1; dk /= 2) {//dk表示步长
        for (i = dk + 1; i <= len; ++i) {//从dk+1处开始对步长为dk的所有元素进行排序，表示进行直接插入排序的次数
            if (a[i] < a[i - dk]) {//后边的元素大于前面的
                int temp = a[i];//保存a[i]元素的值
                for (j = i - dk; j > 0 && temp < a[j]; j -= dk) {                //进行移动位置 注意从-1变味了-dk
                    a[j + dk] = a[j];//后移元素 直接将j位置的元素 移动到j+dk的位置上
                }
                a[j + dk] = temp;//将a[i]元素放到正确的位置上
            }
        }
    }
}

int main() {
    int a[10] = {-99999, 2, -10, 100, -3, 4, 7, 9, -4445, 4123};//-99999元素无效
    for (int x:a) {
        printf("%d\t", x);

    }
    printf("\n");
    shellSort(a, 9);//对下标为1-9的元素进行排序
    for (int x:a) {
        printf("%d\t", x);

    }

    return 0;
}