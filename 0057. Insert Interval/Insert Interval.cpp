class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        int left = 0, right = intervals.size() - 1, target = newInterval[0];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (intervals[left][0] < target)
            ++left;
        intervals.insert(intervals.begin() + left, newInterval);
        vector<vector<int>> res;
        for (const auto& interval : intervals)
        {
            if (res.empty() || (res.back()[1] < interval[0]))
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        intervals.erase(intervals.begin() + left);
        return res;
    }
};