/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    #define ll long long;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = spells.size(), n = potions.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; ++ i) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (spells[i] * 1L * potions[mid] >= success) r = mid - 1;
                else l = mid + 1;
            }
            ans[i] =  n - l;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        for (int &x : spells) {
            long long target = (success - 1) / x;
            if (target < potions.back()) {
                // 这样写每次二分就只用 int 比较，避免把 potions 中的元素转成 long long 比较
                x = potions.end() - upper_bound(potions.begin(), potions.end(), (int) target);
            } else {
                x = 0;
            }
        }
        return spells;
    }
};
// @lc code=end

