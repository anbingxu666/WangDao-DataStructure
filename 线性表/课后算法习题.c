//
// Created by HappyBing on 2019-08-21.
//

#include <cstdio>

#define ElemType int
#define MAX_SIZE 50
//定义顺序表的结构体
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

//题目一：从顺序表中删除最小值的元素并返回删除的值 出错则退出运行
bool deleteMinElem(SqList &list, int &value) {
    //返回值为value
    if (list.length == 0) {
        return false;
    }
    value = list.data[0];
    int index = 0;
    for (int i = 1; i < list.length; ++i) {
        if (list.data[i] < value) {
            index = i;
            value = list.data[i];
        }
    }

    //将最后一个元素放入 i位置的
    list.data[index] = list.data[list.length - 1];
    //线性表的长度减1
    list.length--;
    return true;
}

//题目二：将顺序表L的所有元素逆置
void reverseList(SqList &l) {
    //空表和长度为一的表不需要逆置
    if (l.length == 0 || l.length == 1) {
        return;
    }
    for (int i = 0, j = l.length - 1; i < j; i++, j--) {
        //交换两个元素
        int temp = l.data[i];
        l.data[i] = l.data[j];
        l.data[j] = temp;
    }

}

//题目三：删除所有值为x的元素
//方法1：虚拟构造一个新的数组 利用数组的随机访问 根据不等于X的元素 在原来数组的基础上构造新的数组
void deleteX_1(SqList &list, int value) {
    if (list.length == 0) {
        return;
    }
    int k = 0;//用于记录不等于x的元素个数 同时也是删除x后线性表的下标
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != value) {
            list.data[k] = list.data[i];//将数据赋予 第k个位置的元素
            k++;//伪新数组的下标+1
        }
    }
    list.length = k;
}

//法二：有几个等于X的元素 当前元素就向前移动几个
void deleteX_2(SqList &list, int value) {
    if (list.length == 0) {
        return;
    };
    int k = 0;
    int i = 0;
    while (i < list.length) {
        if (list.data[i] == value) {
            k++;//等于value元素的个数
        } else {
            list.data[i - k] = list.data[i];//当前元素迁移k个元素
        }
        i++;
    }
    list.length = list.length - k;
}

//题目四：删除有序的顺序表的值【s，t】的元素
bool deleteS_T(SqList &l, int s, int t) {
    if (s >= t) {
        return false;
    }
    if (l.length == 0) {
        return false;
    }
    if ((s >= l.data[0] && s <= l.data[l.length - 1]) && (t >= l.data[0] && t <= l.data[l.length - 1])) {
        //如果s和t都在数组值的范围内 时候删除元素
        //利用上面的方法 有种伪造数组的感觉
        int k = 0;
        for (int i = 0; i < l.length; ++i) {
            if (l.data[i] < s || l.data[i] > t) {
                l.data[k] = l.data[i];
                k++;
            }
        }
        l.length = k;
    }
    return true;
}


// 题目五:同4 四的方法可以删除有序的顺序表

// 题目六：方法和3异曲同工
bool delete_Same(SqList &list) {
    if (list.length == 0 || list.length == 1) {//长度为0或者1的时候 无重复元素
        return false;
    }
    int i, j;//i用于记录上一个不一样的元素的下标， j用于循环遍历 从数组的第二个元素（下标为1开始）
    for (i = 0, j = 1; j < list.length; ++j) {
        if (list.data[i] != list.data[j]) {
            list.data[++i] = list.data[j];//原理同3
        }

    }
    list.length = i + 1;//调整表长度 表长度至少为1个因为第一个元素肯定不同
    return true;
}

//题目七：合并两个有序顺序表（合并步骤归并排序的思想差不多）
bool mergeTwoList(SqList &list1, SqList &list2, SqList &list) {
    if (list1.length == 0 || list2.length == 0) {
        return false;
    }
    if (list1.length + list2.length > MAX_SIZE) {
        return false;
    }
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    //将等长部分合并
    while (index1 < list1.length && index2 < list2.length) {
        if (list1.data[index1] <= list2.data[index2]) {
            list.data[index++] = list1.data[index1++];
        } else {
            list.data[index++] = list2.data[index2++];
        }
    }
    //将剩余部分合并
    while (index1 < list1.length) {
        list.data[index++] = list1.data[index1++];
    }
    while (index2 < list2.length) {
        list.data[index++] = list2.data[index2++];
    }
    list.length = index;
    return true;
}

int main() {
    /*题目1测试*/
//    SqList l;
//    l.length = 4;
//    l.data[0] = 11;
//    l.data[1] = 41;
//    l.data[2] = 2;
//    l.data[3] = 31;
//    int value = -1;
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteMinElem(l, value);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\nvalue:-->%d", value);


//    /*题目2测试*/
//    SqList l;
//    l.length = 1;
//    l.data[0] = 11;
//    l.data[1] = 41;
//    l.data[2] = 2;
//    l.data[3] = 31;
//    l.data[4] = 311;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    reverseList(l);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }


//    /*题目3测试*/
//    SqList l;
//    l.length = 5;
//    l.data[0] = 11;
//    l.data[1] = 11;
//    l.data[2] = 2;
//    l.data[3] = 11;
//    l.data[4] = 111;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteX_2(l, 11);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }

//    /*题目4测试*/
//    SqList l;
//    l.length = 5;
//    l.data[0] = 1;
//    l.data[1] = 2;
//    l.data[2] = 31;
//    l.data[3] = 4;
//    l.data[4] = 5;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    deleteS_T(l, 31, 31);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }

//    /*题目6测试*/
//    SqList l;
//    l.length = 7;
//    l.data[0] = 1;
//    l.data[1] = 2;
//    l.data[2] = 2;
//    l.data[3] = 3;
//    l.data[4] = 5;
//    l.data[5] = 5;
//    l.data[6] = 5;
//
//
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    printf("\n");
//    delete_Same(l);
//    for (int i = 0; i < l.length; ++i) {
//        printf("%d\t", l.data[i]);
//    }
//    return 0;

    /*题目7测试*/
    SqList l;
    SqList l1;
    SqList l2;
    l1.length = 3;
    l2.length = 2;
    l1.data[0] = 1;
    l1.data[1] = 10;
    l1.data[2] = 1100;
    l2.data[0] = 4;
    l2.data[1] = 100;
    mergeTwoList(l1, l2, l);


    printf("\n");
    for (int i = 0; i < l.length; ++i) {
        printf("%d\t", l.data[i]);
    }
    return 0;
}