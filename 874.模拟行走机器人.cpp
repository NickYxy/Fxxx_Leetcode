/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 0:north, 1:east, 2:south, 3:west
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int k = 0, ans = 0;
        int x = 0, y = 0;
        set<pair<int, int>> S;
        for (auto& ob : obstacles) S.emplace(ob[0], ob[1]);
        for (int i = 0; i < commands.size(); ++ i) {
            if (commands[i] == -2) {
                k = (k + 4 - 1) % 4;
            } else if (commands[i] == -1) {
                k = (k + 4 + 1) % 4;
            } else {
                for (int j = 0; j < commands[i]; ++ j) {
                    int dx = x + direction[k][0], dy = y + direction[k][1];
                    if (S.count({dx, dy})) break;
                    ans = max(ans, helper(dx, dy));
                    x = dx;
                    y = dy;
                }

            }
        }


        return ans;
    }

    int helper(int x, int y) {
        return x * x + y * y;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0, y=0, k=0, mx=0, d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<pair<int,int>> S;
        for(auto &v: obstacles)
            S.emplace(v[0], v[1]);
        for(auto &t: commands)
            if(t==-2)
                k = (k+3)%4;
            else if(t==-1)
                k = (k+1)%4;
            else
                for(int i=0;i<t;i++){
                    int xx=x+d[k][0], yy=y+d[k][1];
                    if(S.count({xx, yy}))   break;
                    mx = max(mx, xx*xx+yy*yy);
                    x = xx;
                    y = yy;
                }
        return mx;
    }
};
// @lc code=end

