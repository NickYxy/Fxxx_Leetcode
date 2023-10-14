/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

// @lc code=start
class StockPrice {
public:
    unordered_map<int, int> mp;
    multiset<int> s;
    int maxTimestamp;
    StockPrice() {
        maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prevPrice = mp.count(timestamp) ? mp[timestamp] : 0;
        mp[timestamp] = price;
        if (prevPrice > 0) {
            auto it = s.find(prevPrice);
            if (it != s.end()) {
                s.erase(it);
            }
        }
        s.emplace(price);
    }

    int current() {
        return mp[maxTimestamp];
    }

    int maximum() {
        return *s.rbegin();
    }

    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

