class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums)
            ++mp[i];
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
        {
            for (int j = i + 1; j < nums.size() && nums[i] + nums[j] <= 0; ++j)
            {
                int target = -(nums[i] + nums[j]);
                if (target >= nums[j] && mp[target] >= 1 + (nums[i] == target) + (nums[j] == target))
                    res.push_back({nums[i], nums[j], target});
                while (j + 1 < nums.size() && (nums[j] == nums[j + 1]))
                    ++j;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        
        return res;
    }
};