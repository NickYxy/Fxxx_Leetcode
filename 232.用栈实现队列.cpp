/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }

    void push(int x) {
        while (st2.size()) {
            st1.push(st2.top());
            st2.pop();
        }
        st2.push(x);
        while (st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
    }

    int pop() {
        int n = st2.top();
        st2.pop();
        return n;
    }

    int peek() {
        int n = st2.top();
        return n;
    }

    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

