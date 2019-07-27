//
// Created by HappyBing on 2020-03-08.
//

#include <iostream>

using namespace std;

void buildHeap(int *array);

void adjustDown(int *array, int k, int len);

void HeapSort(int *array, int len);

void buildHeap(int *array, int len) {
    // 从第一个非叶子结点调整
    for (int i = len / 2; i >= 1; i--) {
        adjustDown(array, i, len);
    }
}

void adjustDown(int *array, int k, int len) {// 建立大顶堆 从小到大排序
    array[0] = array[k];// 保存第k个元素的值
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && array[i + 1] > array[i]) {
            i++;
        }
        // 这里一定是用array[0]去比较 因为要确定该元素的位置
        // 若用的是array[k] 会因为k是用来暂时记录 array[0] 该放的下标 k会发生变化，导致出错
        if (array[0] >= array[i]) {
            break;
        } else {
            array[k] = array[i];
            k = i;
        }
    }
    array[k] = array[0]; //将第k个元素及其子树调整为堆
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void HeapSort(int *array, int len) {
    buildHeap(array, len);
    for (int i = len; i > 1; i--) {
        swap(&array[1], &array[i]);
        adjustDown(array, 1, i - 1);
    }


}

int main() {
    int array[11] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    buildHeap(array, 10);
    HeapSort(array, 10);
    for (int x : array) {
        cout << x << endl;
    }

}