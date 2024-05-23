class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0, left = 0, leading = 0; i < nums.size(); ++i)
        {
            ++mp[nums[i]];
            while (mp.size() > k)
            {
                if(--mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                ++left;
                leading = 0;
            }
            if (mp.size() == k)
            {
                while (mp[nums[left]] > 1)
                {
                    --mp[nums[left]];
                    ++leading;
                    ++left;
                }
                res += 1 + leading;
            }
        }
        return res;
    }
};