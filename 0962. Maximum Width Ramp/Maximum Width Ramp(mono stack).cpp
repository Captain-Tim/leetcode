class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> mono_stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mono_stk.empty() || (nums[mono_stk.top()] > nums[i]))
                mono_stk.push(i);
        }
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!mono_stk.empty() && nums[mono_stk.top()] <= nums[i])
            {
                res = max(res, i - mono_stk.top());
                mono_stk.pop();
            }
        }
        return res;
    }
};