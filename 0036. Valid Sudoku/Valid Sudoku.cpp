class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIZE = 9;
        vector<unordered_set<char>> rows(SIZE);
        vector<unordered_set<char>> cols(SIZE);
        vector<unordered_set<char>> boxes(SIZE);
        for (int r = 0; r < SIZE; ++r)
        {
            for (int c = 0; c < SIZE; ++c)
            {
                char num = board[r][c];
                if (num != '.')
                {
                    if (rows[r].count(num))
                        return false;
                    rows[r].insert(num);
                    
                    if (cols[c].count(num))
                        return false;
                    cols[c].insert(num);
                    
                    int box_idx = (r / 3) * 3 + c / 3;
                    if (boxes[box_idx].count(num))
                        return false;
                    boxes[box_idx].insert(num);
                }
            }
        }
        return true;
        
    }
};