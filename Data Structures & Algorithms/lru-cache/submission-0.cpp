class Node {
public:
    Node* next = nullptr;
    Node* prev = nullptr;
    int val;
    int key;
    Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), head(new  Node(-1, -1)), tail(new Node(-1, -1)) {
        cache.reserve(capacity);
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache() {
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* req = cache.at(key).get();
        move_to_end(req);
        return req->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() == capacity) {
                // eject the smallest one
                Node* to_delete = head->next;
                remove(to_delete);
                cache.erase(to_delete->key);                
            }
            auto res = make_unique<Node>(key, value);
            Node* raw = res.get();
            cache[key] = std::move(res);
            insert(raw);
        } else {
            Node* req = cache.at(key).get();
            req->val = value;
            move_to_end(req);
        }
    }

private:
// key, node (val)
unordered_map<int, unique_ptr<Node>> cache{};
// front means its least recently used
Node* head;
// back means its most recently used
Node* tail;
int capacity;

void remove(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;
}

// new node
void insert(Node* node) {
    Node* old_tail = tail->prev;
    old_tail->next = node;
    tail->prev = node;

    node->prev = old_tail;
    node->next = tail;
}

void move_to_end(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;
    insert(node);
}
};
