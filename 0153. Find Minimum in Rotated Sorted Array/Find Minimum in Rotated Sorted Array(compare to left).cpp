class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] < nums[right]) // if the sequence is ascending order e.g., [1, 2, 3] (must include this check)
                return nums[left];
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) // note that we need to include =, since it is a lower mid. edge case: [2, 1]
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};