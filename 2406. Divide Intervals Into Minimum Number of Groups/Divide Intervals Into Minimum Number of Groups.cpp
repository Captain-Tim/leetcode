class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> left(intervals.size());
        vector<int> right(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
        {
            left[i] = intervals[i][0];
            right[i] = intervals[i][1];
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int res = 0;
        int cur = 0;
        for (int left_idx = 0, right_idx = 0; left_idx < intervals.size(); )
        {
            if (left[left_idx] <= right[right_idx])
            {
                ++cur;
                res = max(res, cur);
                ++left_idx;
            }
            else
            {
                --cur;
                ++right_idx;
            }
        }
        return res;
    }
};