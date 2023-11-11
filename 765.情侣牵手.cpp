/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0, n = row.size();
        for (int i = 0; i < n - 1; i += 2) {
            if (row[i] == (row[i + 1] ^ 1)) continue;
            for (int j = i + 1; j < n; ++ j) {
                if (row[i] == (row[j] ^ 1)) {
                    swap(row[i + 1], row[j]);
                    ans ++;
                    break;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0, n = row.size();
        unordered_map<int, int> memo;
        for (int i = 0; i < n; ++ i) memo[row[i]] = i;

        for (int i = 0; i < n - 1; i += 2) {
            if (row[i] == (row[i + 1] ^ 1)) continue;

            int p1 = i + 1, p2 = memo[row[i] ^ 1];
            swap(row[p1], row[p2]);
            memo[row[p2]] = memo[row[p1]];
            memo[row[p1]] = p2;
            ans ++;
        }

        return ans;
    }
};
// @lc code=end

