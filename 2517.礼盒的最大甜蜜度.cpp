/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(begin(price), end(price));
        int n = price.size();
        int l = 0, r = price[n - 1] - price[0];
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int cnt = 1;
            for (int i = 0, j; i < n; i = j) {
                j = lower_bound(price.begin() + i + 1, price.end(), price[i] + mid) - price.begin();
                if (j != n) ++ cnt;
            }
            if (cnt >= k) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};

class Solution {
public:
    // 猜答案 ans
    // 1. ans 越小，可以选择的数越多，越有可能 >= k，满足题意
    // 2. ans 越大，可以选择的数越少，甚至可能 < k，不满足题意
    // 单调性 ==> 二分答案
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        // ans 最小为 0，最大为 (max-min) / (k-1)
        int left = 0, right =(price.back() - price.front()) / (k-1);
        while (left < right) {
            int mid = (right - left + 1) / 2 + left;

            // 贪心思想：最小的数必须选
            int cnt = 1;
            int x = price[0];
            for (int i = 1; i < price.size(); ++ i) {
                if (price[i] >= x + mid) {
                    ++ cnt;
                    x = price[i];
                }
            }

            // 这里要注意：返回的值一定是可以在数组中选择 k 个数的
            // 如果 mid = 8 满足，那么 0...7 一定是可以的
            // 尝试 mid = 9，如果不满足，则说明之前的 mid = 8 时，prince[i] == x + 8
            // 并且此时 8 就是答案！
            if (cnt >= k) { // mid 选的 ok，试着大一点
                left = mid;
            } else {    // mid 选大了，不行
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

