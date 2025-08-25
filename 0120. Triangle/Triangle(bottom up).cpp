class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(1, 0);
        for (int layer = 0; layer < triangle.size(); ++layer)
        {
            vector<int> cur(layer + 1, 0);
            for (int i = 0; i < cur.size(); ++i)
            {
                int left_val = (i - 1 >= 0) ? prev[i - 1] : INT_MAX;
                int right_val = (i != prev.size()) ? prev[i] : INT_MAX;
                cur[i] = triangle[layer][i] + min(left_val, right_val);  
            }
            cur.swap(prev);
        }
        int res = INT_MAX;
        for (int i : prev)
            res = min(res, i);
        return res;
    }
};