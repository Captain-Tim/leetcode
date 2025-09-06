class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int NINE = 9;
        const int THREE = 3;
        vector<unordered_set<char>> row_check(NINE);
        vector<unordered_set<char>> col_check(NINE);
        vector<unordered_set<char>> blk_check(NINE);
        for (int i = 0; i < NINE; ++i)
        {
            for (int j = 0; j < NINE; ++j)
            {
                char c = board[i][j];
                if (c == DOT)
                    continue;
                int blk_idx = (i / THREE) * THREE + (j / THREE);
                if (row_check[i].count(c) || col_check[j].count(c) || blk_check[blk_idx].count(c))
                    return false;
                row_check[i].insert(c);
                col_check[j].insert(c);
                blk_check[blk_idx].insert(c);
             }
        }
        return true;
    }
private:
    const char DOT = '.';
};
