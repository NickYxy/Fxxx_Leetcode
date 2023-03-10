/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /**
        使数组能被p整除，也就是sum%p==0，所以我们关注每个数对p的余数
        由于(a+b)%p==(a%p+b%p)%p，遍历一遍，可以求出余数作为目标target
        我们要求的就是片段和%p==target的最短子数组。 可以使用前缀和+哈希表实现。

        前缀和：i+1~j的片段和即0~j的前缀和-0~i的前缀和，利用前缀和，将片段和转化为两数之差
        哈希表：问题转化为两数之差为target，可以仿照两数之和，使用哈希表在O(N)内解决
        注意取模问题：减法取模时，为了避免负数，要+p
        **/
        int target = 0, ans = nums.size(), sum = 0, res; // sum 实际上是取余后的前缀和，result 存储结果
        for (auto& num : nums) target = (target + num) % p;
        if (target == 0) return 0;

        unordered_map<int, int> pos; //用哈希表记录前缀和对应的最大下标
        pos[0] = -1; // [注意] 这一步很关键，当数组没有元素时，余数为 0，由于还没有开始遍历数组，位置为 -1
        for (int i = 0; i < nums.size(); i ++) {
            // 这一步也非常关键，找到元素和的余数为 (sum + p - remainder) % p 的子数组开始位置
            // [注意] 这里需要注意为什么是 (sum + p - remainder) % p
            // 因为子数组要满足元素和 与 整个数组 nums 元素和 mod p 同余
            // 考虑到前缀和结束位置 i 时，余数为 sum，那么子数组开始时，应该与 sum - remainder 同余
            // 注意到我们将余数标准化为正数，位于区间 [0, p)，结合 Java 中 % 运算的性质，得出结论
            sum = (sum + nums[i]) % p, res = (sum - target + p) % p; //计算前缀和，以及要查找的和
            pos[sum] = i; //记录这个前缀和, 更新哈希表中 数组从开始到现在的前缀和除以 p 的余数的位置 i
            ans = min(ans, pos.find(res) == pos.end() ? INT_MAX : i - pos[res]);//查找并比较
        }

        return ans == nums.size() ? -1 : ans;
         // 如果要将数组所有元素删除，则没有任何符合条件的删除方法，因此返回 -1；否则返回 ans
    }
};
// @lc code=end

