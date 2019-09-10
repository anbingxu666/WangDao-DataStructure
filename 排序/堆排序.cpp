//
// Created by Newmor on 2019-08-19.
//

#include <cstdio>


void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

void AdjustDown(int a[], int k, int len) {
    //数组有效果元素的长度从1开始 即第一个数组元素为a[1]
    //在将k位置的元素放在正确的位置的时候也会将k的孩子调整
    a[0] = a[k];//暂存a[i]
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && a[i + 1] > a[i]) {
            i++;
        }
        if (a[0] >= a[i]) {
            break;
        } else {
            a[k] = a[i];//1
            k = i;//2 用k记录位置 以便下次调整

        }

    }
    a[k] = a[0];

}

void BuildHeap(int a[], int len) {
    for (int i = len / 2; i > 0; i--) {
        AdjustDown(a, i, len);
    }
}

void HeapSort(int a[], int len) {
    BuildHeap(a, len);
    for (int i = len; i > 1; --i) {
        //交换首尾元素
        swap(&a[i], &a[1]);
        //调整堆
        AdjustDown(a, 1, i - 1);
    }

}

//判断一个堆是否为大顶堆的算法（小顶堆只需要将所有if中的大于号改为小于号即可）
bool IsMaxHeap(int a[], int len) {
    if (len % 2 == 0) {//len为偶数的时候所对应的完全二叉树又一个单独的分支结点需要独立判断
        if (a[len / 2] < a[len]) {
            return false;
        }
        //判断所有成双入对的结点
        for (int i = len / 2 - 1; i >= 1; --i) {
            if (a[i] < a[2 * i] || a[i] < a[2 * i + 1]) {
                return false;
            }
        }
    } else {//奇数的时候即每个非叶子结点都有两个孩子 直接判断即可
        for (int i = len / 2; i >= 1; --i) {//
            if (a[i] < a[2 * i] || a[i] < a[2 * i + 1]) {
                return false;
            }
        }
    }


    return true;

}

int main() {
    int a[101] = {0, -4, 3, 5, 1, 2, 6, 9, 10, 7, -8};

    for (int i = 1; i <= 10; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    HeapSort(a, 10);
    for (int i = 1; i <= 10; ++i) {
        printf("%d\t", a[i]);
    }

    //测试是否为大顶堆
    printf("\n是否为大顶堆？%d", IsMaxHeap(a, 10));//递增的有序序列当然不是
    BuildHeap(a, 10);//建立大顶堆
    printf("\n是否为大顶堆？%d", IsMaxHeap(a, 10));//递增的有序序列当然不是

    return 0;
}