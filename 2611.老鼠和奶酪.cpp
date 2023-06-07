/*
 * @lc app=leetcode.cn id=2611 lang=cpp
 *
 * [2611] 老鼠和奶酪
 */

// @lc code=start
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> cheeseSub;
        int ans = 0;
        for (int i = 0; i < reward1.size(); ++ i) {
            cheeseSub.push_back(reward1[i] - reward2[i]);
            ans += reward2[i];
        }

        sort(cheeseSub.begin(), cheeseSub.end());
        for (int i = cheeseSub.size() - 1; i >= cheeseSub.size() - k && i >= 0; i --) {
            ans += cheeseSub[i];
        }

        return ans;
    }
};
// @lc code=end

