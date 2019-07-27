////
//// Created by 安炳旭 on 2019-04-18.
////
//
//#include <cstdio>
//#include <algorithm>
////采用大顶堆堆方式升序排序
//void adjustHeap(int a[], int i, int len) {
//
//    //a代表数组 i代表位置 len代表长度
//    int temp = a[i];
//    for (int k = 2 * i + 1; k < len; k = 2 * k + 1) {
//        //选出大的子节点
//        if(k < (len - 1)  && a[k] < a[k+1]){
//            k++;
//        }
//        //如果子节点大，则双亲节点的位置变为子节点
//        if(a[k] > temp){
//            a[i] = a[k];
//            i = k;//i代表temp的最新位置
//        } else{
//            break;
//        }
//    }
//    a[i] = temp;
//}
//void swap(int arr[],int a,int b){
//    int temp = arr[a];
//    arr[a] = arr[b];
//    arr[b] = temp;
//}
//void HeapSort(int arr[],int length){
//
//    //这个步骤用于建立大顶堆
//    for (int i = length / 2 - 1; i >= 0; i--) {
//        //从第一个非叶子结点从下至上，从右至左调整结构
//        adjustHeap(arr, i, length);
//    }
//
//    //2.调整堆结构+交换堆顶元素与末尾元素 12345
//    for (int j = length - 1; j > 0; j--) {
//
//        swap(arr, 0, j);//将堆顶元素与末尾元素进行交换 j代表最后一个元素的下标 同时j也是去掉一个元素后剩下数组的长度
//        adjustHeap(arr, 0, j);//重新对堆进行调整
//    }
//}
//int main() {
//    int a[10] = {4, 3, 5, 1, 2, 6, 9, 10, 7, -8};
//
//    HeapSort(a, 10);
//    for (int i = 0; i < 10; ++i) {
//        printf("%d\t", a[i]);
//    }
//    return 0;
//}