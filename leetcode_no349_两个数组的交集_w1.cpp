/* ------------------------------------------------------------------|
给定两个数组，编写一个函数来计算它们的交集。



示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]


说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。|
-------------------------------------------------------------------*/

/*	双哈希集合法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了96.25%的用户
*	内存消耗：11 MB, 在所有 C++ 提交中击败了5.05%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) {
        return {};
    }
    if (nums1.size() < nums2.size()) {
        return intersection(nums2, nums1);
    }
    //使用set可以建立哈希表保证不重复，同时减少使用map的计数空间
    unordered_set<int> set1;
    unordered_set<int> set2;
    for (auto x : nums1) {
        set1.insert(x);
    }
    for (auto x : nums2) {
        set2.insert(x);
    }
    vector<int> res;
    for (auto x : set2) {
        if (set1.count(x)) {
            res.emplace_back(x);
        }
    }
    return res;
}

int main() {
    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };

    vector<int> res = intersection(nums1, nums2);
}