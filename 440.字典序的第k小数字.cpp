/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k --; //初始化为cur = 1，k需要自减1
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            //统计这棵子树下所有节点数（step）
            while (first <= n) {
                //不能超过n的值，并不是所有节点都有十个子节点
                step += min((long long) n + 1, last) - first;
                first *= 10;
                last  *= 10;
            }
            if (step <= k) { //不在子树中,说明以cur开头的合格节点数不够,cur应该向右走
                k -= step;
                cur ++;
            } else { //在子树中，进入子树,说明以cur开头的合格节点数足够,cur应该向下走
                k --;
                cur *= 10;
            }
        }
        return cur;
    }
};

class Solution {
public:
    int f(int prefix, int n) {
        long long p = 1;
        auto A = to_string(n), B = to_string(prefix);
        int dt = A.size() - B.size();
        int res = 0;
        for (int i = 0; i < dt; i++) {
            res += p;
            p *= 10;
        }
        A = A.substr(0, B.size());
        if (A == B) res += n - prefix * p + 1;
        else if (A > B) res += p;
        return res;
    }
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            int cnt = f(prefix, n);
            if (k > cnt) {
                k -= cnt;
                prefix ++;
            } else {
                k --;
                prefix *= 10;
            }
        }
        return prefix;
    }
};
// @lc code=end

