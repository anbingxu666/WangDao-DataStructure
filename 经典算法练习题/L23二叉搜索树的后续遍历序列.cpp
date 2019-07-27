//
// Created by HappyBing on 2020-01-25.
//
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool judge(vector<int> &s, int left, int right) {
    if (left >= right) {//为什么大于等于有点问题
        return true;
    }
    int rootValue = s[right];
    int i = left;
    //找到第一个比根结点大的元素下标i
    while (s[i] < rootValue) {
        i++;
    }
    int j = i;
    //从该处开始看是否都大于根节点
    while (j < right) {
        if (s[j] < rootValue) {
            return false;
        }
        j++;
    }
    //看左\右子树是否满足要求
    return judge(s, left, i - 1) && judge(s, i, right - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() == 0) {
        return false;
    }
    return judge(sequence, 0, sequence.size() - 1);

}