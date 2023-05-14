/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> mp;
        for (auto& x : barcodes) mp[x] ++;
        vector<pii> slt;
        for (auto it = mp.begin(); it != mp.end(); it ++) {
            slt.push_back({it->first, it->second});
        }
        sort(slt.begin(), slt.end(), [](pii l, pii r){return l.second > r.second;});

        int idx = 0, res_idx = 0;
        while (idx < slt.size()) {
            barcodes[res_idx] = slt[idx].first;
            res_idx += 2;
            slt[idx].second --;
            if (!slt[idx].second) idx ++;
            if (res_idx >= n) res_idx = 1;
        }

        return barcodes;
    }
};
// @lc code=end

