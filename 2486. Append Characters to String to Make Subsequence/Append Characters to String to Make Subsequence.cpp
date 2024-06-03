class Solution {
public:
    int appendCharacters(string s, string t) {
        int t_idx = 0;
        for (int i = 0; i < s.size() && t_idx < t.size(); ++i)
        {
            if (s[i] == t[t_idx])
                ++t_idx;
        }
        return t.size() - t_idx;
    }
};