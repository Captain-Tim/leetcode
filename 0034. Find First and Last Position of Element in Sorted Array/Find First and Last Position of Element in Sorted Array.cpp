class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> not_found{-1, -1};
        int start = bs(nums, target - 1, false);
        int end = bs(nums, target + 1, true);
        if (nums.empty() || nums[start] != target)
            return not_found;
        return {start, end};
    }
    int bs(vector<int>& nums, int target, bool is_upper_mid)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + is_upper_mid) / 2;
            if (is_upper_mid)
            {
                if (nums[mid] >= target)
                    right = mid - 1;
                else
                    left = mid;
            }
            else
            {
                if (nums[mid] <= target)
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return left;
    }
};