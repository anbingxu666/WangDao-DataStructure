//
// Created by HappyBing on 2019-04-11.
//

#include <cstdio>

int findPosition(int *a, int left, int right);

void quickSort(int *a, int left, int right) {
   //递归出口
   if(left >= right){
       return;
   }
   int pos = findPosition(a, left, right);
   //递归进行排序
   quickSort(a, left, pos - 1);
   quickSort(a, pos + 1, right);

}

int findPosition(int *a, int left, int right) {
   int temp = a[left];

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

   return left;
}

int main() {
   printf("待排序序列:\t");
   int a[10] = {4, 3, 5, 2, 2, 6, 9, -10, 7, 8};
   for (int i : a) {
       printf("%d\t", i);
   }
   printf("\n");
   quickSort(a, 0, 9);
   printf("排序序列:\t");

   for (int i : a) {
       printf("%d\t", i);
   }
   return 0;
}