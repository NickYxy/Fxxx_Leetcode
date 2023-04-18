/*
 * @lc app=leetcode.cn id=1679 lang=cpp
 *
 * [1679] K 和数对的最大数目
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int m = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i ++) {
            if (mp[k - nums[i]] > 0) {
                cnt ++;
                mp[k - nums[i]] --;
            } else {
                mp[nums[i]] ++;
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int i,j,res;
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        i = 0; j = nums.size()-1;
        while(i < j) {
            if(nums[i] + nums[j] > k) j--;
            else if(nums[i] + nums[j] < k) i++;
            else {res++; i++; j--;}
        }
        return res;
    }
};
// @lc code=end

