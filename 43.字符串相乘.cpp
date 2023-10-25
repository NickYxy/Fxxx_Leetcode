/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        const int n = num1.size(), m = num2.size();
        vector<int> res(m + n);

        for (int i = n - 1; i >= 0; -- i) {
            for (int j = m - 1; j >= 0; -- j) {
                res[n + m - i - j - 2] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        for (int i = 0; i < m + n; ++ i) cout << res[i] << ' ';

        for (int i = 0, t = 0; i < res.size() || t; ++ i) {
            t += res[i];

            if (i < res.size()) res[i] = t % 10;
            else res.push_back(t % 10);

            t /= 10;
        }

        while (res.size() > 1 && res.back() == 0) res.pop_back();

        string ans;
        for (int i = res.size() - 1; i >= 0; -- i) ans.push_back(res[i] + '0');

        return ans;
    }
};
// @lc code=end

