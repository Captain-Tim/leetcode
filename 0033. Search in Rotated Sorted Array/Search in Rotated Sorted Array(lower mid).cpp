class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            bool mid_in_left = nums[mid] >= nums[0];
            if (mid_in_left)
            {
                if (target > nums[mid] || target < nums[0])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
            {
                if (target > nums[mid] && target < nums[0])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};