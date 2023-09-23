/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
public:
    vector<int> p;
    vector<vector<int>> son;
    vector<int> tag;
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        tag = vector<int>(n);
        p = parent;
        son = vector<vector<int>>(n);
        for (int i = 1; i < n; ++ i) son[p[i]].push_back(i);
    }

    bool lock(int num, int user) {
        if (tag[num]) return false;
        tag[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (tag[num] != user) return false;
        tag[num] = 0;
        return true;
    }

    bool upgrade(int num, int user) {
        for (int cur = num; cur != -1; cur = p[cur]) {
            if (tag[cur]) return false;
        }
        bool have_lock = false;
        queue<int> q;
        q.push(num);
        while (q.size()) {
            int cur = q.front();
            q.pop();
            if (tag[cur]) {
                have_lock = true;
                tag[cur] = 0;
            }
            for (auto j : son[cur]) q.push(j);
        }

        if (!have_lock) return false;
        tag[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

