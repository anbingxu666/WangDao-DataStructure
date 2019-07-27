//
// Created by Newmor on 2019-04-16.
//

#include <cstdio>

#define MAX 100

void merge(int a[], int L1, int R1, int L2, int R2) {
    int temp[MAX];
    int i = L1;
    int j = L2;
    int k = 0;

    while (i <= R1 && j <= R2) {
        if (a[i] > a[j]) {
            temp[k++] = a[j++];
        }
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
    }

    while (i <= R1) temp[k++] = a[i++];
    while (j <= R2) temp[k++] = a[j++];

    for(int q = L1;q <= R2;++q){
        a[q] = temp[q-L1];
    }
}

void sort(int a[],int start,int end){
    if(start < end){
        int mid = (start+end)/2;
        sort(a,start,mid);
        sort(a,mid+1,end);
        merge(a, start,mid,mid+1,end);
    }
}

int main() {
    int a[11] = {1,4, 3, 5, 1, 2, 6, 9, 10, 7, 8};
    //归并排序：时间复杂度O（nlogn） 空间复杂度O（n） 是一种基于分治的稳定排序算法
    sort(a, 0, 10);
    for (int i = 0; i < 11; ++i) {
        printf("%d\t", a[i]);
    }
    return 0;
}