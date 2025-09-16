class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int res = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (last_seen.count(s[i]) && last_seen[s[i]] >= left)
            {
                res = max(res, i - left);
                left = last_seen[s[i]] + 1;
            }
            last_seen[s[i]] = i;
        }
        res = max(res, static_cast<int> (s.size() - left));
        return res;
    }
};