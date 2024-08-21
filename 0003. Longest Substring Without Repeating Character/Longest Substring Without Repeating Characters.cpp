class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int res = 0;
        for (int i = 0, leftmost = 0; i < s.size(); ++i)
        {
            if (last_seen.count(s[i]) && last_seen[s[i]] >= leftmost)
            {
                res = max(res, i - last_seen[s[i]]);
                leftmost = last_seen[s[i]] + 1;
            }
            else
                res = max(res, i - leftmost + 1);
            last_seen[s[i]] = i;
        }
        return res;
    }
};