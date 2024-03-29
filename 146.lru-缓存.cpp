/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val) :key(_key), val(_val), left(NULL), right(NULL){}
    }*L,  *R;
    unordered_map<int, Node*> hash;
    int n;

    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert(Node* p) {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1), R = new Node(-1, -1);
        L->right = R;
        R->left = L;
    }

    int get(int key) {
        if (hash.count(key) == 0) return -1;
        else {
            auto p = hash[key];
            remove(p);
            insert(p);
            return p->val;
        }
    }

    void put(int key, int value) {
        if (hash.count(key) != 0) {
            auto p = hash[key];
            p->val = value;
            remove(p);
            insert(p);
        } else {
            if (hash.size() == n) {
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto q = new Node(key, value);
            hash[key] = q;
            insert(q);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

