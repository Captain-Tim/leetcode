class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = -1;
        for (int i = 0, sum = 0; i < nums.size(); ++i)
        {
            sum = (sum + nums[i]) % k;
            if (prefix_sum.count(sum) && prefix_sum[sum] != (i - 1))
                return true;
            else if (!prefix_sum.count(sum))
                prefix_sum[sum] = i;
        }
        return false;
    }
};
