////
//// Created by 安炳旭 on 2019-04-11.
////
//
//#include <cstdio>
//
//void merge(int a[], int L, int M, int R);
//
//void mergeSort(int a[], int L, int R) {
//    if (L == R) {
//        return;
//    } else {
//
//        //取中间的数，进行拆分
//        int M = (L + R) / 2;
//
//        //左边的数不断进行拆分
//        mergeSort(a, L, M);
//
//        //右边的数不断进行拆分
//        mergeSort(a, M + 1, R);
//
//        //合并
//        merge(a, L, M + 1, R);
//
//
//    }
//
//
//}
//
//void merge(int a[], int L, int M, int R) {
//    // a:数组
//    // L：数组第一个
//    // R：数组最后一个
//    // M: 分割点
//
//    //新建两个数组
//    // [L,M) [M,R]
//    int leftArray[M - L];
//    int rightArray[R - M + 1];
//
//    //将M左边的全装入第一个数组
//    for (int i = 0; i < M - L; ++i) {
//        //0 1 2 3 4 5   = L + 0 1 2 3 4 5 6
//        leftArray[i] = a[L+i];
//    }
//    //将 M右边的全装入第二个 数组
//    for (int j = 0; j < (R - M + 1); ++j) {
//        rightArray[j] = a[M + j];
//    }
//    //合并两个数组
//    int i = 0;
//    int j = 0;
//    int k = L;
//    while (i < (M - L) && j < (R - M + 1)) {
//        if (leftArray[i] < rightArray[j]) {
//            a[k] = leftArray[i];
//            i++;
//            k++;
//        }
//        if (leftArray[i] >= rightArray[j]) {
//            a[k] = rightArray[j];
//            j++;
//            k++;
//        }
//    }
//    //如果任何一个数组还有剩余则全都插到后面️
//    while (i < (M - L)) {
//        a[k] = leftArray[i];
//        i++;
//        k++;
//    }
//    while (j < (R - M + 1)) {
//        a[k] = rightArray[j];
//        k++;
//        j++;
//    }
//
//
//}
//
//int main() {
//    int a[11] = {1,4, 3, 5, 1, 2, 6, 9, 10, 7, 8};
//    mergeSort(a, 0, 10);
//    for (int i = 0; i < 11; ++i) {
//        printf("%d\t", a[i]);
//    }
//    return 0;
//}