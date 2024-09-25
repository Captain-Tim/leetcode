class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            bool mid_in_left = nums[left] < nums[mid];
            if (mid_in_left)
            {
                if (nums[mid] > target && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid;
            }
            else
            {
                if (nums[right] < target || target < nums[mid])
                    right = mid - 1;
                else
                    left = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};