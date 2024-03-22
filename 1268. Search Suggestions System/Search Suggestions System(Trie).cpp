class Solution {
private:
    static const int ALPHABET_NUM = 26;
    static const int SUGGESTION_NUM = 3;
    struct TrieNode
    {
        bool is_end_here;
        vector<TrieNode*> next;
        TrieNode()
        : is_end_here(false)
        , next(ALPHABET_NUM, nullptr)
        {
            
        };
    };
    TrieNode* root;
    void dfs(TrieNode* root, string& cur_str, vector<vector<string>>& res)
    {
        if (!root || res.back().size() == SUGGESTION_NUM)
            return;
        if (root->is_end_here)
            res.back().push_back(cur_str);
        for (int i = 0; i < ALPHABET_NUM && res.back().size() < SUGGESTION_NUM; ++i)
        {
            if (root->next[i])
            {
                cur_str.push_back(i + 'a');
                dfs(root->next[i], cur_str, res);
                cur_str.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        
        for (const string& s : products)
        {
            TrieNode* cur = root;
            for (const char& c : s)
            {
                int key = c - 'a';
                if (cur->next[key] == nullptr)
                    cur->next[key] = new TrieNode();
                cur = cur->next[key];
            }
            cur->is_end_here = true;
        }
        vector<vector<string>> res;
        TrieNode* cur = root;
        string cur_str = "";
        for (const char& c : searchWord)
        {
            res.push_back({});
            if (!cur)
                continue;
            int key = c - 'a';
            cur = cur->next[key];
            cur_str.push_back(c);
            dfs(cur, cur_str, res);
        }
        return res;
    }
};