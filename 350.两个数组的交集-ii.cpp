/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

    }
};
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c1 = collections.Counter(nums1)
        c2 = collections.Counter(nums2)

        ans = []
        for n1, v1 in c1.items():
            for n2, v2 in c2.items():
                if n1 == n2:
                    for i in range(min(v1, v2)):
                        ans.append(n1)

        return ans
// @lc code=end

