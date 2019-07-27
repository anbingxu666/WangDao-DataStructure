////
//// Created by 安炳旭 on 2019-04-10.
////
//
//#include <cstdio>
//
//void bubbleSort(int a[], int len) {
//
//
//    //趟数
//    for (int i = 0; i < len - 1; ++i) {
//
//        //比较次数
//        for (int j = 0; j < len - i - 1; ++j) {
//
//            if (a[j + 1] < a[j]) {
//                //交换
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    int a[10] = {4, 3, 5, 1, 2, 6, 9, 10, 7, 8};
//
//    bubbleSort(a, 10);
//    for (int i = 0; i < 10; ++i) {
//        printf("%d\t", a[i]);
//    }
//    return 0;
//}