class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int res = INT_MIN;
        for (int i : nums)
        {
            cur_sum += i;
            res = max(cur_sum, res);
            cur_sum = max(0, cur_sum);
        }
        return res;
    }
};