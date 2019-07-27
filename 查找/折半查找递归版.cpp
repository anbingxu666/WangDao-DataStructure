//
// Created by HappyBing on 2019-10-14.
//

#include <cstdio>

int BinarySearchRecursion(int A[], int left, int right, int k) {
    if (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] == k) {
            return mid;
        } else if (A[mid] < k) {
            return BinarySearchRecursion(A, mid + 1, right, k);
        } else {
            return BinarySearchRecursion(A, left, mid - 1, k);
        }
    }
    return -1;
}

int main() {
    int A[10] = {-100,1,3,6,7,9,10,100,1000,10000};
    printf("下标为->%d",BinarySearchRecursion(A,0,9,100));
    return 0;
}