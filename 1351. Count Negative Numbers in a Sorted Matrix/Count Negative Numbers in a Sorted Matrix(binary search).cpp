class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int const ROW = grid.size();
        int const COL = grid[0].size();
        int res = 0;
        for (vector<int>& row : grid)
        {
            int left = 0;
            int right = COL - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2; //lower mid
                if (row[mid] >= 0)
                    left = mid + 1;
                else
                    right = mid;
            }
            res += (COL - left - (row[left] >= 0));
        }
        return res;
    }
};