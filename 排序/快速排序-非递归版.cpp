//
// Created by Newmor on 2019-09-18.
//
#include <cstdio>

int Partition(int a[], int p, int r) {

    int temp = a[p];
    while (p < r) {
        //若以第一个元素为划分对时候 先右后左！！！！！
        while (p < r && temp <= a[r]) {
            r--;
        }
        a[p] = a[r];

        while (p < r && temp >= a[p])
            p++;
        a[r] = a[p];

    }
    a[p] = temp;
    return p;

}

void quickSortNonRecrusion(int a[], int p, int r) {
//    stack<int> boundStack;

    //使用数组模拟一个栈
    int boundStack[100] = {0};
    int top = -1;


    int low = p;
    int high = r;
    //完成初始划分
    int q = Partition(a, p, r);

    //入栈
    if (q > low + 1) {
        boundStack[++top] = low;
        boundStack[++top] = q - 1;
    }
    if (q < high - 1) {
        boundStack[++top] = q + 1;
        boundStack[++top] = high;
    }

    while (top >= 0) {
        high = boundStack[top--];
        low = boundStack[top--];
        int par = Partition(a, low, high);
        if (par > low + 1) {
            boundStack[++top] = low;
            boundStack[++top] = par - 1;
        }
        if (par < high - 1) {
            boundStack[++top] = par + 1;
            boundStack[++top] = high;

        }
    }
}


int main() {
    int a[10] = {-9999, -666, 4, 3000, 2, 1, -1001, 12, -14, 7};//数组有序元素从下标为1的元素开始

    quickSortNonRecrusion(a, 1, 9);
    for (int i = 1; i <= 9; ++i) {
        printf("%d\t", a[i]);
    }
}