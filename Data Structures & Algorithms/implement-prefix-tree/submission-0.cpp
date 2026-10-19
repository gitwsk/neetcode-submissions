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
public:
    PrefixTree() {
        root = new TrieNode();
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
