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
                if (board[r][c] == DOT)
                    continue;
                char cur_char = board[r][c];
                int blk_idx = (r / 3) * 3 + (c / 3);
                if (rows[r].count(cur_char) || cols[c].count(cur_char) || blks[blk_idx].count(cur_char)) 
                    return false;
                rows[r].insert(cur_char);
                cols[c].insert(cur_char);
                blks[blk_idx].insert(cur_char);
            }
        }
        return true;
    }
private:
    const char DOT = '.';
};
