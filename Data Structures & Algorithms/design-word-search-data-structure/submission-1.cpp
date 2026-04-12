class Trie {
public:
    void insert(const string& word) {
        auto* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }

    bool contains(const string& word) {
        return dfs(word, 0, root);
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children{};
        bool end = false;
    };
    TrieNode* root = new TrieNode();

    bool dfs(const string& word, int j, TrieNode* node) {
        TrieNode* curr = node;
        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (curr->children.count(c) == 0) {
                    return false;
                }
                curr = curr->children[c];
            } else {
                for (const auto& [key, child] : curr->children) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->end;
    }

};

class WordDictionary {
public:
    WordDictionary() = default;
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.contains(word);
    }
private:
    Trie trie{};
};
