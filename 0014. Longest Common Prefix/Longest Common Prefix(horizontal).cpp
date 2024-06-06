class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int str_idx = 1; str_idx < strs.size(); ++str_idx)
        {
            int min_len = min(res.size(), strs[str_idx].size());
            int common_length = 0;
            while (common_length < min_len && res[common_length] == strs[str_idx][common_length])
                ++common_length;
            res = res.substr(0, common_length);
        }
        return res;
    }
};