class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> intervals_sorted(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
        {
            intervals_sorted[i] = intervals[i];
            intervals_sorted[i].push_back(i);
        }
        auto comparator = [](vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0];
        };
        sort(intervals_sorted.begin(), intervals_sorted.end(), comparator);
        vector<int> res;
        for (int i = 0; i < intervals_sorted.size(); ++i)
        {
            int target = intervals[i][1];
            int left = 0;
            int right = intervals_sorted.size() - 1;
            while (left  < right)
            {
                int mid = left + (right - left) / 2;
                if (intervals_sorted[mid][0] < target)
                    left = mid + 1;
                else
                    right = mid;
            }
            res.push_back((intervals_sorted[left][0] < target) ? -1 : intervals_sorted[left][2]);
        }
        return res;
    }
};