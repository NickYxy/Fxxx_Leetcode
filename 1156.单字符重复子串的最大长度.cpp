/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 */

// @lc code=start
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        unordered_map<int, int> mp; // 记录每个字母出现的总次数，判断是否可以借字母
        for (auto x : text) mp[x] ++;
        int nums[n], idx = -1; // 将原串处理为(a, 1), (b, 3)的形式，这里可以优化为用6个变量，不用数组

        int res = 0;
        for (int i = 0; i < n; ++ i) {
            int j = i;
            while (j < n && text[j] == text[i]) j ++;
            nums[++ idx] = j - i; // 记录该字母连续出现的次数
            if (idx > 1 && nums[idx - 1] == 1 && i > 1 && text[i - 2] == text[i])
            // 两个相邻的串只隔一个字母，小于总数时，合并+1；
                res = max(res, min(nums[idx] + nums[idx - 2] + 1, mp[text[i]]));
            res = max(res, min(nums[idx] + 1, mp[text[i]])); // 其他情况，小于总数时，+1；
            i = j - 1;
        }

        return res;
    }
};
// @lc code=end

