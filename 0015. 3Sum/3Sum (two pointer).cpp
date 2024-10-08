class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
        {
            if (!i || (nums[i] != nums[i - 1]))
            {
                int left = i + 1;
                int right = nums.size() - 1;
                int target = -nums[i];
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > target)
                        --right;
                    else if (sum < target)
                        ++left;
                    else
                    {
                        res.push_back({nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right - 1] == nums[right])
                            --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};