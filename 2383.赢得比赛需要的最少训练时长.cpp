/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sumEnergy = 0, ans = 0;
        for (auto& x : energy) sumEnergy += x;
        if (sumEnergy >= initialEnergy) ans += (sumEnergy - initialEnergy + 1);
        for (auto& exp : experience) {
            if (initialExperience <= exp) {
                ans += exp - initialExperience + 1;
                initialExperience += (exp - initialExperience + 1);

            }
            initialExperience += exp;
        }

        return ans;
    }
};
// @lc code=end

