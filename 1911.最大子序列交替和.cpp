/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // 大多数情况下，我们要找的是一个奇数序列，这样的话，偶数个数会比奇数个数多一个
        // 第二种情况，即使偶数比奇数多一个，可能也不是最大值，这时候序列个数是偶数
        // 可以从零开始构建序列，遇到小的就加入，更小的就替换，大的就算偶数序列
        // 可以考虑用栈，锯齿形的加入，那么肯定是最优解，因为一直在加正数
        int maxQ = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        stack<int> stk;
        stk.push(nums[0]);
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 1; i < n; ++ i) {
            if (stk.size()&& (stk.size() % 2 == 0)  && nums[i] < stk.top()) {
                stk.pop();
                stk.push(nums[i]);
            }
            else if (stk.size()&& (stk.size() % 2 == 1)  && nums[i] > stk.top()) {
                stk.pop();
                stk.push(nums[i]);
            } else {
                stk.push(nums[i]);
            }
        }
        if (stk.size() % 2 == 0) stk.pop();
        vector<int> v;
        while(stk.size()) {
            v.push_back(stk.top());
            stk.pop();
        }
        for (int i = 0; i < v.size(); ++ i) {
            if (i % 2 == 1) ans -= v[i];
            else ans += v[i];
        }

        if (ans > maxQ) return ans;
        else return maxQ;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            ans += max(nums[i] - nums[i - 1], 0);
        }

        return ans;
    }
};
// @lc code=end

