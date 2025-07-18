class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cur_sum = 0;
        for (int i : nums)
            cur_sum ^= i;
        return cur_sum;
    }
};
