/*
 * @lc app=leetcode.cn id=2600 lang=cpp
 *
 * [2600] K 件物品的最大和
 */

// @lc code=start
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if (k < numOnes) return k;
        else {
            k -= numOnes;
            ans += numOnes;
        }

        if (k < numZeros) return ans;
        else {
            k -= numZeros;
        }

        return ans - k;
    }
};

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return k > (numOnes + numZeros) ? (numZeros + numOnes * 2 - k) : min(k, numOnes);
    }
};
// @lc code=end

