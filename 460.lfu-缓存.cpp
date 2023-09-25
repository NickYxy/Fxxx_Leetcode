/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val){
            key = _key;
            val = _val;
            left = right = NULL;
        }
    };
    struct Block{
        Block *left, *right;
        Node *head, *tail;
        int cnt;
        Block(int _cnt) {
            cnt = _cnt;
            head = new Node(-1, -1), tail = new Node(-1, -1);
            left = right = NULL;
            head->right = tail;
            tail->left = head;
        }
        ~Block() {
            delete head;
            delete tail;
        }
        void remove(Node* p) {
            p->left->right = p->right;
            p->right->left = p->left;
        }
        void insert(Node* p) {
            p->right = head->right;
            head->right->left = p;
            p->left = head;
            head->right = p;
        }
        bool empty() {
            return head->right == tail;
        }
    }*head, *tail;
    int n;
    unordered_map<int, Block*> hash_block;
    unordered_map<int, Node*> hash_node;

    void insert(Block* b) { // 在b的右边加入新块
        auto cur = new Block(b->cnt + 1);
        cur->right = b->right;
        b->right->left = cur;
        b->right = cur;
        cur->left = b;
    }

    void remove(Block* b) {
        b->left->right = b->right;
        b->right->left = b->left;
        delete b;
    }

    LFUCache(int capacity) {
        n = capacity;
        head = new Block(0), tail = new Block(INT_MAX);
        head->right = tail, tail->left = head;
    }

    int get(int key) {
        if (hash_block.count(key) == 0) return -1;
        auto block = hash_block[key];
        auto node = hash_node[key];
        block->remove(node);
        if (block->right->cnt != (block->cnt + 1)) insert(block);
        block->right->insert(node);
        hash_block[key] = block->right;
        if (block->empty()) remove(block);
        return node->val;
    }

    void put(int key, int value) {
        if (!n) return;
        if (hash_block.count(key)) {
            hash_node[key]->val = value;
            get(key);
        } else {
            if (hash_block.size() == n) {
                auto p = head->right->tail->left;
                head->right->remove(p);
                if (head->right->empty()) remove(head->right);
                hash_block.erase(p->key);
                hash_node.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            if (head->right->cnt > 1) insert(head);
            head->right->insert(p);
            hash_block[key] = head->right;
            hash_node[key] = p;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

