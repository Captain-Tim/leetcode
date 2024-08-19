class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](pair<int, int>&a, pair<int, int>& b)
        {
            return a.first < b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
        for (int i = 0; i < points.size(); ++i)
        {
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (pq.size() < k || pq.top().first > distance)
            {
                pq.push({distance, i});
                if (pq.size() > k)
                    pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};