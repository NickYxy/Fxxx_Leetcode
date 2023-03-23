/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
       int n = l.size();
       vector<bool> ans;
       for (int i = 0; i < n; i ++) {
           bool res = check(nums, l[i], r[i]);
           ans.push_back(res);
       }

       return ans;
    }

    bool check(vector<int>& nums, int l, int r) {
        if (r == l || (r - l == 1)) return true;
        vector<int> tmp;
        for (int i = l; i <= r; i ++) {
            tmp.push_back(nums[i]);
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 1; i < tmp.size() - 1; i ++) {
            if (tmp[i - 1] - tmp[i] != tmp[i] - tmp[i + 1]) return false;
        }

        return true;
    }
};
// @lc code=end

