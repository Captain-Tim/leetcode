class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        using pii = pair<int, int>;
        stack<pii> stk;
        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (stk.empty() || heights[i] > stk.top().first)
            {
                stk.push({heights[i], i});
            }
            else
            {
                int start_position;
                while (!stk.empty() && stk.top().first >= heights[i])
                {
                    start_position = stk.top().second;
                    res = max(res, stk.top().first * (i - stk.top().second));
                    stk.pop();
                }
                stk.push({heights[i], start_position});
            }
        }
        while (!stk.empty())
        {
            res = max(res, stk.top().first * (int) (heights.size() - stk.top().second));
            stk.pop();
        }
        return res;
    }
};