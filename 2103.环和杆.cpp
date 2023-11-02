/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        vector<int> count(10);

        for (int i = 0; i < n; i += 2) {
            if (rings[i] == 'G') count[rings[i + 1] - '0'] |= 1;
            if (rings[i] == 'R') count[rings[i + 1] - '0'] |= 2;
            if (rings[i] == 'B') count[rings[i + 1] - '0'] |= 4;
        }

        int ans = 0;
        for (int i = 0; i < 10; ++ i) {
            if (count[i] == 7) ans ++;
        }

        return ans;
    }
};
class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        vector<set<char>> v(10);
        for (int i = 1; i < n; i += 2) {
            v[(rings[i] - '0')].insert(rings[i - 1]);
        }

        int ans = 0;
        for (auto& s : v) {
            if (s.size() == 3) ans ++;
        }

        return ans;
    }
};
// @lc code=end

