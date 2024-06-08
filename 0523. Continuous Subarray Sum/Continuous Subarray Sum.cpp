class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_remainder;
        prefix_remainder.insert({0, -1});
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            sum %= k;
            if (prefix_remainder.count(sum) && prefix_remainder[sum] < i - 1)
                return true;
            else if (prefix_remainder.count(sum) == 0)
                prefix_remainder[sum] = i;
        }
        return false;
    }
};
