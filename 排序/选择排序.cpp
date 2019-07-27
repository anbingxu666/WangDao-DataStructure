////
//// Created by 安炳旭 on 2019-04-11.
////
//
//#include <cstdio>
//
//void selectSort(int *a, int len) {
//
//    for (int i = 0; i < len - 1; ++i) {
//        //选出最小的下标
//        int minIndex = i;
//        for(int j = i + 1;j < len;++j){
//            if(a[minIndex] > a[j]){
//                minIndex = j;
//            }
//
//            //交换元素位置
//            if(minIndex!= i){
//                int temp = a[minIndex];
//                a[minIndex] = a[i];
//                a[i] = temp;
//            }
//        }
//    }
//}
//int main() {
//    int a[10] = {4, 3, 5, 1, 2, 6, 9, 10, 7, 8};
//
//    selectSort(a, 10);
//    for (int i : a) {
//        printf("%d\t", i);
//    }
//    return 0;
//}