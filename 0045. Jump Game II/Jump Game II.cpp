class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int cur_end = 0;
        int cur_far = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            cur_far = max(cur_far, i + nums[i]);
            if (cur_end == i)
            {
                ++res;
                cur_end = cur_far;
            }
        }
        return res;
    }
};