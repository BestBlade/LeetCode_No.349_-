/* ------------------------------------------------------------------|
�����������飬��дһ���������������ǵĽ�����



ʾ�� 1��

���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2]
ʾ�� 2��

���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[9,4]


˵����

�������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳��|
-------------------------------------------------------------------*/

/*	˫��ϣ���Ϸ�
*
*	ִ����ʱ��8 ms, ������ C++ �ύ�л�����96.25%���û�
*	�ڴ����ģ�11 MB, ������ C++ �ύ�л�����5.05%���û�
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
    //ʹ��set���Խ�����ϣ��֤���ظ���ͬʱ����ʹ��map�ļ����ռ�
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