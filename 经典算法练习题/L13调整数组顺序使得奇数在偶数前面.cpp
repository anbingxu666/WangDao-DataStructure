//
// Created by HappyBing on 2020-01-13.
//

#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array) {
    //算法本质：插入排序 --> 将奇数插入到偶数前面
    for (int i = 1; i < array.size(); ++i) {
        //从第二个元素开始比较 若是奇数则向前移动
        int temp = array[i];//保存第i个位置应该插入到数
        int j = i;//使用临时遍历j用于确定第i个元素的下标j（若不使用i的复制j 则会造成i向前回溯 影响算法的效率）
        if (temp % 2 == 1) {//是奇数
            while (j > 0 && array[j - 1] % 2 == 0) {//若前面是偶数则移动
                array[j] = array[j - 1];
                j--;
            }
            array[j] = temp;
        }
    }
}

//int main() {
//
//    vector<int> a = {1, 2, 3, 4};
//    reOrderArray(a);
//    for (int aa:a) {
//        cout << aa << endl;
//    }
//}