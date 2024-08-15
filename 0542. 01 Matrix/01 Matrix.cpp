class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int ROW = mat.size();
        const int COL = mat[0].size();
        const int LONGEST_DISTANCE = ROW + COL - 2;
        vector<vector<int>> res(ROW, vector<int>(COL, LONGEST_DISTANCE));
        for (int r = 0; r < ROW; ++r)
        {
            for (int c = 0; c < COL; ++c)
            {
                if (mat[r][c] == 0)
                    res[r][c] = 0;
                else
                {
                    int up = r - 1 >= 0 ? res[r - 1][c] : LONGEST_DISTANCE;
                    int left = c - 1 >= 0 ? res[r][c - 1] : LONGEST_DISTANCE;
                    res[r][c] = min(up, left) + 1;
                }
            }
        }
        for (int r = ROW - 1; r >= 0; --r)
        {
            for (int c = COL - 1; c >= 0; --c)
            {
                int down = r + 1 < ROW ? res[r + 1][c] : LONGEST_DISTANCE;
                int right = c + 1 < COL ? res[r][c + 1] : LONGEST_DISTANCE;
                res[r][c] = min(res[r][c], min(down, right) + 1);
            }
        }
        return res;
    }
};