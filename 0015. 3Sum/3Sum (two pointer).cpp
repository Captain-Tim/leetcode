class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int cur = 0; cur < nums.size() && nums[cur] <= 0; )
        {
            int left = cur + 1;
            int right = nums.size() - 1;
            int target = -nums[cur];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum < target)
                    ++left;
                else if (sum > target)
                    --right;
                else
                {
                    res.push_back({nums[cur], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    ++left;
                }
            }
            while (cur + 1 < nums.size() && nums[cur] == nums[cur + 1])
                ++cur;
            ++cur;
        }
        return res;
    }
};