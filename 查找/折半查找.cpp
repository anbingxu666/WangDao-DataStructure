//
// Created by Newmor on 2019-10-14.
//

#include <cstdio>
#include <cstdlib>

typedef struct SeqList {
    int len;
    int *elem;
} SqList;

//数组版本
int BinarySearch(int A[], int left, int right, int k) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == k) {
            return mid;
        } else if (A[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

//顺序表版本
int BinarySearch2(SqList *sqList, int k) {
    int left = 0;
    int right = sqList->len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (sqList->elem[mid] == k) {
            return mid;
        } else if (sqList->elem[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    //算法二测试
//    SqList *sqList = (SqList *) malloc(sizeof(SqList));
//    sqList->len = 10;
//    sqList->elem = (int *) malloc(sizeof(int) * sqList->len);
//    for (int i = 0; i < 10; ++i) {
//        sqList->elem[i] = i;
//    }
//    for (int i = 0; i < 10; ++i) {
//        printf("%d\t", sqList->elem[i]);
//    }
//    printf("下标为->%d\n", BinarySearch2(sqList,5));

    //算法一测试
    int A[10] = {-100, 1, 3, 6, 7, 9, 10, 100, 1000, 10000};
    printf("下标为->%d", BinarySearch(A, 0, 9, 10000));
    return 0;
}