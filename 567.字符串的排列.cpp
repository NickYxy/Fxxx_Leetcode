/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2) return false;

        int a[26] = {0};
        int cnt = 0;
        for (int i = 0; i < l1; i ++) {
            a[s1[i] - 'a'] ++;
            cnt ++;
        }

        int left = 0, right = 0;
        while (right < l2) {
            a[s2[right] - 'a'] --;
            while (a[s2[right] - 'a'] < 0) {
                a[s2[left] - 'a'] ++;
                left ++;
                cnt ++;
            }
            cnt --;
            right ++;
            if (cnt == 0) return true;
        }
        return false;
    }
    }
};
// @lc code=end

