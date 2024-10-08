class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            res[i] = res[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2, product = 1; i >= 0; --i)
        {
            product *= nums[i + 1];
            res[i] *= product;
        }
        return res;
    }
};