class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        vector<vector<int>> res;
        int cur_idx = 0;

        while (cur_idx < intervals.size() && intervals[cur_idx][1] < newInterval[0])
        {
            res.push_back(intervals[cur_idx]);
            ++cur_idx;
        }
        
        while (cur_idx < intervals.size() && newInterval[1] >= intervals[cur_idx][0])
        {
            newInterval[0] = min(newInterval[0], intervals[cur_idx][0]);
            newInterval[1] = max(newInterval[1], intervals[cur_idx][1]);
            ++cur_idx;
        }
        res.push_back(newInterval);
        
        while (cur_idx < intervals.size())
            res.push_back(intervals[cur_idx++]);
        return res;
    }
};