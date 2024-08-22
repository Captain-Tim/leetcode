class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i : s)
        {
            if (!s.count(i - 1))
            {
                int length = 1;
                while (s.count(i + 1))
                {
                    ++i;
                    ++length;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};