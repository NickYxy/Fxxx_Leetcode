/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */

// @lc code=start
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size(), q = queries.size();
        vector<array<int, 26>> sum(n + 1);
        // sum[i]到sum[j]表示i到j之间的字符出现的次数的前缀和
        for (int i = 0; i < n; ++ i) {
            sum[i + 1] = sum[i];
            sum[i + 1][s[i] - 'a'] ++;
            // sum[i + 1][s[i] - 'a'] %= 2; // 偶数是0 也可以优化成这样
        }

        vector<bool> ans;
        for (auto& querie : queries) {
            int left = querie[0], right = querie[1], k = querie[2];
            int odd = 0;
            for (int i = 0; i < 26; ++ i) {
                // 如果字符出现次数为奇数，+1；否则+0
                odd += (sum[right + 1][i] - sum[left][i]) % 2;
            }

            ans.emplace_back((odd / 2) <= k);
        }

        return ans;
    }
};

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
        int n = s.length(), q = queries.size(), sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            int bit = 1 << (s[i] - 'a');
            sum[i + 1] = sum[i] ^ bit; // 该比特对应字母的奇偶性：奇数变偶数，偶数变奇数
        }

        vector<bool> ans(q); // 预分配空间
        for (int i = 0; i < q; i++) {
            auto &query = queries[i];
            int left = query[0], right = query[1], k = query[2];
            int m = __builtin_popcount(sum[right + 1] ^ sum[left]);
            ans[i] = m / 2 <= k;
        }
        return ans;
    }
};
// @lc code=end

