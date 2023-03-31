/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        //string从后遍历，用num记录#的个数，当遇到正常节点时，#的个数-2，
        //并将该节点转化成#，num+1，，整体即为num-1; 当出现num的个数不足2时，即false，最终也须保证num为1。
        int n = preorder.size();
        int num = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (preorder[i] == ',') continue;
            if (preorder[i] == '#') num ++;
            else {
                while (i >= 0 && preorder[i] != ',') i--; //节点数字可能有多位
                if (num >= 2) num --;
                else return false;
            }
        }
        if (num != 1) return false;
        return true;
    }
};
// @lc code=end

