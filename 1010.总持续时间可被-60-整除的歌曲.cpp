/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // 两数之和的变形
        // 用一个数组记录每个时间对应的模60结果的总和，如果两个数的模相加为60，则这两个数相加是60的倍数
        int ans = 0;
        vector<int> count(60);
        for (auto& t : time) {
            if (t % 60 == 0) ans += count[0];
            else ans += count[60 - (t % 60)];
            count[t % 60] ++;
        }

        return ans;
    }
};
// @lc code=end

