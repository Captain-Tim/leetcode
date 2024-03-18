class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto comparator = [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        };
        sort(points.begin(), points.end(), comparator);
        int res = 1;
        int right_most = points[0][1];
        for (const auto& point : points)
        {
            if (point[0] > right_most)
            {
                right_most = point[1];
                ++res;
            }
        }
        return res;
    }
};