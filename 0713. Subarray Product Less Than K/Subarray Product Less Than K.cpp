class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int SIZE = nums.size();
        int product = 1;
        int res = 0;
        for (int i = 0, left = 0; i < SIZE; ++i)
        {
            product *= nums[i];
            while (left <= i && product >= k)
                product /= nums[left++];
            res += (i - left + 1);
        }
        return res;
    }
};