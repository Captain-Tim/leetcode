class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int red = 0;
        const int blue = 2;
        int right = nums.size() - 1;
        int left = 0;
        int cur_idx = 0;
        while (cur_idx <= right)
        {
            if (nums[cur_idx] == red)
                swap(nums[cur_idx++], nums[left++]);
            else if (nums[cur_idx] == blue)
                swap(nums[cur_idx], nums[right--]);
            else
                ++cur_idx;
        }
        return;
    }
};