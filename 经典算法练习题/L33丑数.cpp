//
// Created by HappyBing on 2020-06-01.
//
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

#include <cstdio>
#include <vector>

using namespace std;

int GetUglyNumber_Solution(int index) {
    if (index < 7)
        return index;

    vector<int> array;
    int p2 = 0, p3 = 0, p5 = 0;
    int num = 1;
    array.push_back(num);
    while (array.size() < index) {
        num = min(min(array[p2]*2, array[p3]*3), array[p5]*5);
        if (array[p2] * 2 == num)
            p2++;
        if (array[p3] * 3 == num)
            p3++;
        if (array[p5] * 5 == num)
            p5++;
        array.push_back(num);
    }
    return num;
}