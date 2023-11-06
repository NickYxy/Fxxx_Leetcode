/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        for (auto& w : words) {
            int temp = 0;
            for (auto ch : w) {
                temp |= (1 << (ch - 'a'));
            }
            nums.push_back(temp);
        }

        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                if (!(nums[i] & nums[j])) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }
};
// @lc code=end

