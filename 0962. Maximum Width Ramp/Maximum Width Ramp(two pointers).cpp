class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> right_max(nums.size());
        int cur_max = INT_MIN;
        for (int i = right_max.size() - 1; i >= 0; --i)
        {
            cur_max = max(cur_max, nums[i]);
            right_max[i] = cur_max;
        }
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < nums.size())
        {
            if (nums[left] <= right_max[right])
            {
                res = max(res, right - left);
                ++right;
            }
            else
                ++left;
        }
        return res;
    }
};