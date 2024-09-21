class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIZE = 9;
        vector<unordered_set<char>> rows(SIZE);
        vector<unordered_set<char>> cols(SIZE);
        vector<unordered_set<char>> blks(SIZE);
        
        for (int r = 0; r < SIZE; ++r)
        {
            for (int c = 0; c < SIZE; ++c)
            {
                if (board[r][c] == '.')
                    continue;
                char cur_num = board[r][c];
                int blk_idx = (r / 3) * 3 + (c / 3);
                if (rows[r].count(cur_num) || cols[c].count(cur_num) || blks[blk_idx].count(cur_num)) 
                    return false;
                rows[r].insert(cur_num);
                cols[c].insert(cur_num);
                blks[blk_idx].insert(cur_num);
            }
        }
        return true;
    }
};