/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        /*
            1,初始方向向上
            2.一轮指令后，方向可能不变，也可能变
            3.方向发生变化，最多四次迭代就能变回初始方向，而且一定能变回初始方向。这点很重要，大家想一想
            4.不管是第一轮指定还是第N轮指定以后，第一次达到同方向，看这次的位置是不是(0,0)，如果是，则困于循环。
            如果不是，则不会困住（假设落在(1,1)，则再来一轮达到同方向，下次的落点会在 (2,2)，下下次会是(3,3)，以此类推）
        */
        int x = 0, y = 0;
        int direction = 0;
        vector<vector<int>> vecs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = instructions.size();
        for (int i = 0; i < n; i ++) {
            if (instructions[i] == 'G') {
                x += vecs[direction][0];
                y += vecs[direction][1];
            } else if (instructions[i] == 'L') {
                direction = (direction + 3) % 4;
            } else {
                direction = (direction + 1) % 4;
            }
        }

        if (direction == 0) return x == 0 && y == 0;

        return true;
    }
};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        /*
            1,初始方向向上
            2.一轮指令后，方向可能不变，也可能变
            3.方向发生变化，最多四次迭代就能变回初始方向，而且一定能变回初始方向。这点很重要，大家想一想
            4.不管是第一轮指定还是第N轮指定以后，第一次达到同方向，看这次的位置是不是(0,0)，如果是，则困于循环。
            如果不是，则不会困住（假设落在(1,1)，则再来一轮达到同方向，下次的落点会在 (2,2)，下下次会是(3,3)，以此类推）
        */
        int x = 0, y = 0;
        int direction = 0;
        int dx[4] = {0, 1, 0,-1};
        int dy[4] = {1, 0,-1, 0};
        int n = instructions.size();
        for (int i = 0; i < n; i ++) {
            if (instructions[i] == 'G') {
                x += dx[direction];
                y += dy[direction];
            } else if (instructions[i] == 'L') {
                direction = (direction + 3) % 4;
            } else {
                direction = (direction + 1) % 4;
            }
        }

        if (direction == 0) return x == 0 && y == 0;

        return true;
    }
};
// @lc code=end

