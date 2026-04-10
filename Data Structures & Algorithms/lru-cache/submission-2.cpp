class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
            head = make_unique<Node>(-1, -1);
            tail = make_unique<Node>(-1, -1);
            head.get()->next = tail.get();
            tail.get()->prev = head.get();
            memo.reserve(capacity);
    }
    
    int get(int key) {
        if (memo.find(key) == memo.end()) return -1;
        Node* req = memo[key].get();
        append(req);
        return req->val;
    }
    
    void put(int key, int value) {
        if (memo.find(key) != memo.end()) {
            // contains the key
            Node* req = memo[key].get();
            req->val = value;
            append(req);
        } else {
            if (memo.size() == capacity) {
                Node* to_remove = head->next;
                popleft(to_remove);
                memo.erase(to_remove->key);
            }
            auto node = make_unique<Node>(key, value);
            memo[key] = std::move(node);
            Node* borrowed = memo[key].get();
            append(borrowed);
        }
    }

private:
struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int key;
    int val;
    Node(int key, int value) : key(key), val(value) {}
};

    unique_ptr<Node> head;
    unique_ptr<Node> tail;
    unordered_map<int, unique_ptr<Node>> memo{};
    int capacity;

    void popleft(Node* old_head) {
        Node* next = old_head->next;
        Node* prev = old_head->prev;

        next->prev = prev;
        prev->next = next;
    }

    void append(Node* new_tail) {
        if (new_tail->prev && new_tail->next) {
            new_tail->prev->next = new_tail->next;
            new_tail->next->prev = new_tail->prev;
        }
        Node* old_tail  = tail.get()->prev;
        old_tail->next = new_tail;
        tail->prev = new_tail;

        new_tail->prev = old_tail;
        new_tail->next = tail.get();
    }
};
