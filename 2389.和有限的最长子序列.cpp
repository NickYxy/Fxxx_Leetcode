/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // 思考过后才发现排序后贪心得到的最优解和子序列的意思是一样的
        // 差别只是[1,2] 和[2, 1]，但题目只要求最长长度，所以不影响
        sort(nums.begin(), nums.end());
        int m = nums.size(), n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i ++) {
            int sum = 0;
            for (int j = 0; j < m; j ++) {
                sum += nums[j];
                if (sum <= queries[i]) ans[i] ++;
                else break;
            }
        }
        return ans;
    }
    }
};

// 排序 + 前缀和 + 上界二分
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int m = nums.size(), n = queries.size();
        vector<int> presum(m + 1), ans(n);
        for (int i = 0; i < m; i ++) presum[i + 1] = presum[i] + nums[i];
        for (int i = 0; i < n; i ++) {
            int q = queries[i];
            ans[i] = upper_bound(presum.begin(), presum.end(), q) - presum.begin() - 1;
        }

        return ans;
    }
};
// @lc code=end

