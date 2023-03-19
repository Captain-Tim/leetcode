class WordDictionary {
private:
    struct TrieNode
    {
        const int alphabet_size = 26;
        vector<TrieNode*> children;
        bool is_end_of_word;
        TrieNode()
        : children(alphabet_size, nullptr)
        , is_end_of_word(false)
        {
        };
    };
    const char dot = '.';
    TrieNode* root;
    bool helper(string& word, int idx, TrieNode* cur)
    {
        if (!cur)
            return false;
        if (idx == word.size())
            return cur->is_end_of_word;
        if (word[idx] == dot)
        {
            for (TrieNode* tmp : cur->children)
            {
                if (helper(word, idx + 1, tmp))
                    return true;
            }
            return false;
        }
        else
            return helper(word, idx + 1, cur->children[word[idx] - 'a']);
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (const char& c : word)
        {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->is_end_of_word = true;
        return;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
