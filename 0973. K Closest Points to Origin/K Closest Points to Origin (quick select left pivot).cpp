class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0;
        int right = points.size() - 1;
        while (true)
        {
            int pivot = partition(points, left, right);
            if (pivot > k - 1)
                right = pivot - 1;
            else if (pivot < k - 1)
                left = pivot + 1;
            else
                break;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    int partition(vector<vector<int>>& points, int left, int right)
    {
        int pivot_dist = distance(points[left]);
        for (int i = left; i <= right; )
        {
            if (distance(points[i]) > pivot_dist)
                swap(points[right--],  points[i]);
            else
                ++i;
        }
        swap(points[right], points[left]);
        return right;
    }
    int distance(vector<int>& p)
    {
        return p[0] * p[0] + p[1] * p[1];
    }
};