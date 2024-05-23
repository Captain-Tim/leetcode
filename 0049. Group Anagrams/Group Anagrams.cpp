class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        for (string& s : strs)
        {
            string key = countSort(s);
            if (mp.find(key) == mp.end())
            {
                mp[key] = res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(s);
        }
        return res;
    }
private:
    const int ALPHABET_NUM = 26;
    string countSort(string& s)
    {
        vector<int> freq(ALPHABET_NUM, 0);
        for (char c : s)
            ++freq[c - 'a'];
        string s_sorted;
        for (int i = 0; i < ALPHABET_NUM; ++i)
            s_sorted += string(freq[i], 'a' + i);
        return s_sorted;
    }
};