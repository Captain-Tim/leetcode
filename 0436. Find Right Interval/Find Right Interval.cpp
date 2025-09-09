class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> sort_start;
        sort_start.reserve(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
            sort_start.push_back({intervals[i][0], i});
        sort(sort_start.begin(), sort_start.end());
        vector<int> res;
        res.reserve(intervals.size());
        for (auto& vec : intervals)
        {
            int target = vec[1];
            int left = 0;
            int right = sort_start.size() - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (sort_start[mid][0] < target)
                    left = mid + 1;
                else
                    right = mid; 
            }
            int result = (sort_start[left][0] >= target) ? sort_start[left][1] : -1;
            res.push_back(result);
        }
        return res;
    }
};
