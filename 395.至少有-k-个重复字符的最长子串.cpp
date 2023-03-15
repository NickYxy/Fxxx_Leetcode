/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        //分治：对于一个字符串来说，如果要求子串最少出现k次，那么如果某些字母出现的次数小于k,
        //这些字母一定不会出现在最长的子串中，并且这些字母将整个字符子串分割成小段，这些小段有可能是最长的
        //但是由于被分割了，还是要检查这一小段，如果某些字母出现的次数小于k,会将小段继续分割下去,
        //比如字符串"aacbbbdc"，要求最少出现2次,我们记录左右闭区间，，
        //第一轮[0,7]，处理"aacbbbdc"，d只出现了一次不满足，于是递归解决区间[0,5]、[7,7]
        //第二轮[0,5]，处理"aacbbb"，  c只出现了一次不满足，于是递归解决区间[0,1]、[3,4]
        //第二轮[7,7]，处理"c"，       c只出现了一次不满足，不继续递归
        //第三轮[0,1]，处理"aa"，      满足出现次数>=2,ret=2
        //第三轮[3,4]，处理"bbb"，     满足出现次数>=2 ret=3;
        int n = s.size();
        if (k <= 1) return n;
        if (s.empty() || s.size() < k) return 0;

        vector<int> hash(128, 0);
        for (char& c : s) hash[c] ++;

        int i = 0;
        while (i < n && hash[s[i]] >= k) i ++;
        if (i == n) return n;

        int l = longestSubstring(s.substr(0, i), k);
        while (i < n && hash[s[i]] < k) i ++;
        int r = longestSubstring(s.substr(i), k);

        return max(l, r);
    }
};
// @lc code=end

