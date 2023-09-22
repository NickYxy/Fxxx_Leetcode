/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children; // 先保证每个是1
        if (money < 7) return 0;
        int cnt = 0;
        while (money >= 7 && children) {
            money -= 7;
            children --;
            if (children == 0 && money != 0) break;// 如果钱没有用完，证明最后一个8不正确
            if (money != 3 ||(money == 3 && children != 1)) cnt ++;
        }

        return cnt;
    }
};
// @lc code=end

