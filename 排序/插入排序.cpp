//
// Created by HappyBing on 2019-04-11.
//
#include <cstdio>
void insertSort(int *a,int len){

    for(int i = 1; i <= len - 1; ++i){
        int temp = a[i];
        //移出空位
        while(i > 0 && temp < a[i - 1]){
            a[i] = a[i - 1];
            i --;
        }
        a[i] = temp;
    }
}
int main() {
    int a[10] = {4, 3, 5, 1, 2, 6, 9, 10, 7, 8};

    insertSort(a, 10);
    for (int i : a) {
        printf("%d\t", i);
    }
    return 0;
}