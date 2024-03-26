class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        int res = 0;
        for (int left = COL - 1, row = 0; row < ROW; ++row)
        {
            while (left >= 0 && grid[row][left] < 0)
                --left;
            res += COL - left - 1;
        }
        return res;
    }
};