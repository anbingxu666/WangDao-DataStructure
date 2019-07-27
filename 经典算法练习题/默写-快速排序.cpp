////
//// Created by HappyBing on 2020-02-14.
////
//
//
//
//#include <cstdio>
//
//// 5 1 2 3 4 5 5 9 8
//int partition(int arr[], int left, int right) {
//    int temp = arr[left];
//    while (left < right) {
//        while (left < right && temp <= arr[right]) {
//            right--;
//        }
//        arr[left] = arr[right];
//        while (left < right && temp >= arr[left]) {
//            left++;
//        }
//        arr[right] = arr[left];
//    }
//    arr[left] = temp;
//    return left;
//}
//
//void quickSort(int arr[], int left, int right) {
//    if (left < right) {
//        int pos = partition(arr, left, right);
//        quickSort(arr, left, pos - 1);
//        quickSort(arr, pos + 1, right);
//    }
//}
//
//int main(){
//    int arr[10] = {1,11,-1,30,88,111,-11,1,2,3};
//    quickSort(arr,0,9);
//    for(int x:arr){
//        printf("%d\t",x);
//    }
//}