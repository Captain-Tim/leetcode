/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        using pii = pair<int, int>;
        stack<pii> mono_stk;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            int start_idx = i;
            while (!mono_stk.empty() && mono_stk.top().second > heights[i])
            {
                res = max(res, (i - mono_stk.top().first) * mono_stk.top().second);
                start_idx = mono_stk.top().first;
                mono_stk.pop();
            }
            mono_stk.push({start_idx, heights[i]});
        }
        while (!mono_stk.empty())
        {
            res = max(res, ((int) heights.size() - mono_stk.top().first) * mono_stk.top().second);
            mono_stk.pop();
        }
        return res;
    }
};
// @lc code=end

