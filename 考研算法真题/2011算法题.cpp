//
// Created by Newmor on 2019-10-18.
//

/*
 *
 *2011年算法题：
 *
 * 最优解好难想啊😢
 * 提供一个O（n）的简单思路，双指针问题。将两个元素比较大小，谁小移动谁的指针
 * 同时记录移动次数，根据情况返回当前指针所指向的位置的数值。
 *
 * O(logN)的算法是王道上的答案，这道题也是《算法导论》上的一道题
 *
 * */
#include <cstdio>

//该算法可以写成递归版的更加简洁 但不好理解 所以还是抄王道的吧 😂
bool findMidOlogN(int A[], int B[], int len, int &mid) {
    int a_left = 0, a_right = len - 1, a_m, b_left = 0, b_right = len - 1, b_m;

    while (a_left != a_right || b_left != b_right) {
        a_m = (a_left + a_right) / 2;
        b_m = (b_left + b_right) / 2;
        if (A[a_m] == B[b_m]) {
            mid = A[a_m];
            return true;
        } else if (A[a_m] < B[b_m]) {//A数组的中为谁<B数组的中位数的时候，那么整体的中位数位于A-miid的右边，B-mid的左边
            if ((a_left + a_right) % 2 == 0) {//判断当前数组的长度是否为奇数
                a_left = a_m;//（如过想使用递归的化 修改这里 共可以减少4行代码量）
                b_right = b_m;
            } else {
                a_left = a_m + 1;
                b_right = b_m;
            }
        } else {//同上， 这次只要把B数组看成A数组重复上面但操作即可（数组的前后顺序是相对的）
            if ((b_left + b_right) % 2 == 0) {
                b_left = b_m;
                a_right = a_m;
            } else {
                b_left = b_m + 1;
                a_right = a_m;
            }
        }
    }
    mid = A[a_left] < B[b_left] ? A[a_left] : B[b_right];
    return true;

}


//时间复杂度为O(n) 空间复杂度为O（1）的算法
bool findMidOn(int A[], int B[], int len, int &mid) {
    //建立双指针
    int i_a = 0;
    int i_b = 0;
    //初始化计数变量
    int count = 1;
    while (i_a < len && i_b < len) {
        if (A[i_a] < B[i_b]) {
            i_a++;
            count++;
        } else {
            i_b++;
            count++;
        }
        //移动次数等于n代表已经到了n/2位置
        if (count == len) {
            //若i_a已经遍历完毕则返回另一个指针下标所指向的元素
            if (i_a == len) {
                mid = B[i_b];
                return true;
            } else if (i_b == len) {
                mid = B[i_a];
                return true;
            } else {
                mid = A[i_a] < B[i_b] ? A[i_a] : B[i_b];
                return true;

            }
        }
    }
    return false;
}

int main() {
    int B[5] = {2, 4, 6, 8, 10};
    int A[5] = {1, 2, 4, 7, 9};
    int n = 5;
    int mid = 0;
    findMidOlogN(A, B, n, mid);
    printf("-->%d", mid);
    return 0;
}