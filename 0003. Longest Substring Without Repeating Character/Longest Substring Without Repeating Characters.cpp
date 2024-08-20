class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        int leftmost = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= leftmost)
            {
                res = max(res, i - leftmost);
                leftmost = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
        res = max(res, (int) s.size() - leftmost);
        return res;
    }
};