/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n;) {
            int j = i + 1;
            int len = words[i].size();
            while (j < n && (len + 1 + words[j].size()) <= maxWidth) len += (1 + words[j].size()), j++;

            string line;
            if (j == n || j - i == 1) {
                // 左对齐
                line += words[i];
                for (int k = i + 1; k < j; ++ k) line += ' ' + words[k];
                while (line.size() < maxWidth) line += ' ';
            } else {
                // cnt:空格数量 r:剩余空间
                int cnt = j - i - 1, r = maxWidth - len + cnt; // 前面len已经把空隙加上了
                int k = 0; // k: 左边需要多添加的一个空格
                line += words[i];
                while (k < (r % cnt)) line += string(r / cnt + 1, ' ') + words[i + k + 1], k ++;
                while (k < cnt) line += string(r / cnt, ' ') + words[i + k + 1], k ++;
            }
            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
// @lc code=end

