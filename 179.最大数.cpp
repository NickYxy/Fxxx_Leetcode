/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        for(auto& num : nums) {
            if (!(num == 0 && ans[0] == '0')) {
                ans += to_string(num);
            }
        }
        return ans;
    }
};
// @lc code=end

