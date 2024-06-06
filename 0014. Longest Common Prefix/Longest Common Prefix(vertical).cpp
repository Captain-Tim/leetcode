class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int char_idx = 0; char_idx < strs[0].size(); ++char_idx)
        {
            char cur_char = strs[0][char_idx];
            for (string& s : strs)
            {
                if (s.size() == char_idx || s[char_idx] != cur_char)
                    return res;
            }
            res += cur_char;
        }
        return res;
    }
};