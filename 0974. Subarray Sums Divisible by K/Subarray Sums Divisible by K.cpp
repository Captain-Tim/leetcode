class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i : nums)
        {
            sum = (sum + i) % k;
            if (sum < 0)
                sum += k;
            res += prefix_sum[sum];
            ++prefix_sum[sum];
        }
        return res;
    }
};
