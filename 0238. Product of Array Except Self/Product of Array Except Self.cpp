class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for (int i = res.size() - 1, prod = 1; i >= 0; --i)
        {
            res[i] = prod;
            prod *= nums[i];
        }
        for (int i = 0, prod = 1; i < res.size(); ++i)
        {
            res[i] *= prod;
            prod *= nums[i];
        }
        return res;
    }
};