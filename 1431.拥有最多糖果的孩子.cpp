/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = candies.size();
        int maxV = 0;
        vector<bool> ans(m, false);
        for (auto& candy : candies) maxV = max(maxV, candy);

        for (int i = 0; i < m; i ++) {
            if (candies[i] + extraCandies >= maxV) ans[i] = true;
        }

        return ans;
    }
};

func kidsWithCandies(candies []int, extraCandies int) []bool {
    m := len(candies)
    maxV := 0
    for _, v := range candies {
        if v > maxV {
            maxV = v
        }
    }

    ans := make([]bool, m)
    for i, _ := range(candies) {
        if candies[i] + extraCandies >= maxV {
            ans[i] = true
        }
    }
    return ans
}
// @lc code=end

