class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert_idx = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i])
                swap(nums[insert_idx++], nums[i]);
        return;
    }
};