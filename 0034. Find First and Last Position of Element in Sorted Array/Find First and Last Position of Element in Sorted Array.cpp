class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BS(nums, target, false), BS(nums, target, true)};
    }
    int BS(vector<int>& nums, int target, bool is_finding_last)
    {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + is_finding_last) / 2;
            if (!is_finding_last)
            {
                if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid;
            }
            else
            {
                if (nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};