class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> prefix_sum{{0, -1}};
        int cur_sum = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (vowel_to_int.count(s[i]))
                cur_sum ^= vowel_to_int[s[i]];
            if (prefix_sum.count(cur_sum))
                res = max(res, i - prefix_sum[cur_sum]);
            else
                prefix_sum.insert({cur_sum, i});
        }
        return res;
    }
private:
    unordered_map<char, int> vowel_to_int{
        {'a', 0b10000},
        {'e', 0b01000},
        {'i', 0b00100},
        {'o', 0b00010},
        {'u', 0b00001}
    };
};