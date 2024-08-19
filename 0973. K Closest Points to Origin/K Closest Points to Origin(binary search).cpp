class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> distance;
        vector<int> remaining_idx;
        int farthest = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int cur_distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            distance.push_back(cur_distance);
            remaining_idx.push_back(i);
            farthest = max(farthest, cur_distance);
        }
        int left = 0;
        int right = farthest;
        vector<vector<int>> res;
        while (k)
        {
            int mid = left + (right - left + 1) / 2;
            vector<int> closer;
            vector<int> further;
            for (int i : remaining_idx)
            {
                if (distance[i] > mid)
                    further.push_back(i);
                else
                    closer.push_back(i);
            }
            if (closer.size() > k)
            {
                right = mid - 1;
                remaining_idx.swap(closer);
            }
            else
            {
                left = mid;
                for (int i : closer)
                    res.push_back(points[i]);
                remaining_idx.swap(further);
                k -= closer.size();
            }
        }
        return res;
    }
};