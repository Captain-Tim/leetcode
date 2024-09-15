class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> code;
        code['a'] = 1;
        code['e'] = 2;
        code['i'] = 4;
        code['o'] = 8;
        code['u'] = 16;
        const int ALL_EVEN_CODE_NUM = 0;
        
        unordered_map<int, int> first_seen;
        first_seen[ALL_EVEN_CODE_NUM] = -1;
        int xor_sum = ALL_EVEN_CODE_NUM;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int code_num = code.count(s[i]) ? code[s[i]] : 0;
            xor_sum ^= code_num;
            if (xor_sum != ALL_EVEN_CODE_NUM && first_seen.count(xor_sum) == 0)
                first_seen[xor_sum] = i;
            else
                res = max(res, i - first_seen[xor_sum]);
        }
        return res;
    }
};