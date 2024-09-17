class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> code_book;
        code_book['a'] = 1;
        code_book['e'] = 2;
        code_book['i'] = 4;
        code_book['o'] = 8;
        code_book['u'] = 16;
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = -1;
        const int ALL_VOWEL_EVEN = 0;
        int sum = ALL_VOWEL_EVEN;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int code = code_book.count(s[i]) ? code_book[s[i]] : 0;
            sum ^= code;
            if (prefix_sum.count(sum))
                res = max(res, i - prefix_sum[sum]);
            else
                prefix_sum[sum] = i;
        }
        return res;
    }
};