/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ans = 0;
        int n = tiles.size();
        vector<bool> used(n, false);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, used, ans, "");
        return ans;
    }

    void dfs(string tiles, vector<bool>& used, int& ans, string res) {
        if (res.size() > 0) ans ++;
        for (int i = 0; i < tiles.size();) {
            if (used[i] == true) {
                i ++;
                continue;
            }
            res += tiles[i];
            used[i] = true;
            dfs(tiles, used, ans, res);
            used[i] = false;
            res = res.substr(0, res.size() - 1);
            i ++;
            while (i > 0 && i < tiles.size() && tiles[i] == tiles[i - 1]) i ++;
        }
    }
};

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        set<char> tile;
        int n = tiles.length();
        for (char c : tiles) {
            count[c]++;
            tile.insert(c);
        }
        return dfs(count, tile, n) - 1;
    }

    int dfs(unordered_map<char, int>& count, set<char>& tile, int i) {
        if (i == 0) {
            return 1;
        }
        int res = 1;
        for (char t : tile) {
            if (count[t] > 0) {
                count[t]--;
                res += dfs(count, tile, i - 1);
                count[t]++;
            }
        }
        return res;
    }
};
// @lc code=end

