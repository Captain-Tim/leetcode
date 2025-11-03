class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for (string& s : strs)
        {
            int len = min(common.size(), s.size());
            int new_len = 0;
            for (int i = 0; i < len && common[i] == s[i]; ++i)
                ++new_len;
            common = common.substr(0, new_len);
        }
        return common;
    }
};