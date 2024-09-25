class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int idx = 0;
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
            res.push_back(intervals[idx++]);
        while (idx < intervals.size() && newInterval[1] >= intervals[idx][0])
        {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            ++idx;
        }
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin() + idx, intervals.end());
        return res;
    }
};