/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        /**
            1.给三个变量a，b，c初始值设为INT_MIN，目的是记录前三大的数，a>b>c

            2.如果num比a都大，那么a，b，c三个值都得更新

            如果num被a，b卡住了，更新bc的值

            如果num被b，c卡住了，就更新c的值

            其他情况：如果比c小，如果等于a或者b或者c了，continue

            3.最后理应返回c的值，但是c如果没有值的话，依照题意返回最大的值
        **/
        int n = nums.size();
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for (auto& num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (max1 > num && num > max2) {
                max3 = max2;
                max2 = num;
            } else if (max2 > num && num > max3) {
                max3 = num;
            }
        }

        return max3 == LONG_MIN ? max1 : max3;
    }
};
// @lc code=end

