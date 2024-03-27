class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int size = nums.size();
        for (int i = 0; i < size; ++i)
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < size; ++i)
            // avoid integer overflow
            if (nums[i] != i + 1)
                return i + 1;
        return size + 1;
    }
};