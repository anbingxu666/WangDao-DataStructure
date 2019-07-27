//
// Created by Newmor on 2019-09-22.
//



#include <cstdio>
#include <algorithm>

using namespace std;

//找到第k小的数字 规定最小的数字是第0小
int findKMin(int a[], int left, int right, int k) {
    int temp = a[left];
    int low = left;
    int high = right;

    while (left < right) {
        while (left < right && a[right] >= temp) {
            right--;
        }
        a[left] = a[right];

        while (left < right && a[left] <= temp) {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    printf("\n");

    for (int i = low; i <= high; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    //上面内容除了不能使用形参之外和快排的分割一模一样
    if (left == k) {
        return a[left];
    } else if (left > k) {
        //从zuo边找
        return findKMin(a, low, left - 1, k);
    } else {
        //从you找
        return findKMin(a, left + 1, high, k);//王道这里写错了⚠️
    }


}


//方法二：建立堆并输出第k个

//方法三：快速排序 然后输出第k个
int main() {
    printf("待排序序列:\t");
    int a[5] = {3, 1, 2, 6, 4};
    for (int i : a) {
        printf("%d\t", i);
    }

    int k = 5;
    printf("\n%d\n", findKMin(a, 0, 4, k - 1));//k-1就可以得到第k小 从 1开始的


    printf("排序序列:\t");
    sort(a, a + 5);
    for (int i : a) {
        printf("%d\t", i);
    }


}