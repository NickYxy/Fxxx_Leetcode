/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        // 首先找到所有的子字符串，重复的也算
        // 枚举每个字母的贡献，其实对于某个串"A××A××A"
        // 中间的那个A能够为包括它、且边界不触碰到左右两个A的范围内的子串贡献一分，
        // 即："A××[A]××A"，"A×[×A]××A"，"A[××A]××A"，"A[××A×]×A"，"A[××A××]A"，
        // "A×[×A××]A"，"A××[A××]A"，"A××[A×]×A"，"A×[×A×]×A"，一共9个
        //（左边界可以从中间的A开始往左扩三步，右边界同理，3*3=9）。这样一来思路就清晰了，
        // 以某个字母为中心，它可以往左右扩展到这个字母再度出现，在这个范围内用乘法原理计算出它的贡献分累加到答案上即可。
        unordered_map<char, vector<int>> idx;
        for (int i = 0; i < s.size(); ++ i) idx[s[i]].emplace_back(i);

        int ans = 0;
        for (auto &&[_, arr] : idx) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size() - 1; i ++) {
                ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }

        return ans;
    }
};
// @lc code=end

