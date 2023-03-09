/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 从后往前遍历，如果该元素加上它的值能使它到达最后一行，就继续向前，并舍弃后面的元素（保持t = 1）
        // 否则就往前看，并让t加1；如果到数组的第一位数字，并且这个时候t > 1,即需要一步以上才能到达尾，则失败。
        int n = nums.size();
        int t = 1;
        for (int i = n - 2; i >= 0; i --) {
            if (nums[i] >= t) t= 1;
            else t ++;
            if (i == 0 && t > 1) return false;
        }
        return true;
    }
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 想象你是那个在格子上行走的小人，格子里面的数字代表“能量”，你需要“能量”才能继续行走。
        // 每次走到一个格子的时候，你检查现在格子里面的“能量”和你自己拥有的“能量”哪个更大，取更大的“能量”！
        // 如果你有更多的能量，你就可以走的更远啦！~
        int n = nums.size();
        int power = nums[0];
        if (n <= 1) return true;
        for (int i = 0; i < n; i ++) {
            power --;
            if (power < 0) return false;
            power = max(power, nums[i]);
            if (power >= 0 && i == n - 1) return true;
        }
        return false;
    }
};
// @lc code=end

