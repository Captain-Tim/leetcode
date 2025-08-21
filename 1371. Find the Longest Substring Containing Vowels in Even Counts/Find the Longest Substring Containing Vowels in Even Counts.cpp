class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> last_seen{{0, -1}};
        int cur_sum = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (vowel_to_int.count(s[i]))
                cur_sum ^= vowel_to_int[s[i]];
            if (last_seen.count(cur_sum))
                res = max(res, i - last_seen[cur_sum]);
            else
                last_seen.insert({cur_sum, i});
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