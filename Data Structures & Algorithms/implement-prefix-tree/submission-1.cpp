class PrefixTree {
private:
    struct TrieNode {
        TrieNode * children[26];
        bool isEndOfWord;
        TrieNode () {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode *root;

        // Helper function to safely delete dynamically allocated memory
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            clear(node->children[i]);
        }
        delete node;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
     ~PrefixTree() {
        clear(root);
    }
    
    void insert(string word) {
        // if (!word.size()) {
            TrieNode *curr = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->isEndOfWord = true;
        // }
    }
    
    bool search(string word) {
        // if (!word.size()) {
            TrieNode *curr = root;
            for (char c : word) {
                int idx = c - 'a';
                //idx exists
                if (curr->children[idx]) {
                    curr = curr->children[idx];
                } else {
                    return false;
                }
            }
        // } 
        // else {
        //     return false;
        // }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        // if (!prefix.size()) {
            TrieNode * curr = root;
            for (char c : prefix) {
                int idx = c - 'a';
                if (curr->children[idx]) {
                    curr = curr->children[idx];
                } else {
                    return false;
                }
            }
            return true;
        // }
    }
};
