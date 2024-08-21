class Solution {
private:
    const int ROW = 9;
    const int COL = 9;
    const int ROW_PER_BOX = 3;
    const int COL_PER_BOX = 3;
    const char EMPTY = '.';
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < ROW; ++r)
            if (!checkRowise(board, r))
                return false;
        for (int c = 0; c < COL; ++c)
            if (!checkColumnwise(board, c))
                return false;
        for (int r = 0; r < ROW_PER_BOX; ++r)
            for (int c = 0; c < COL_PER_BOX; ++c)
                if (!checkSubboxes(board, r, c))
                    return false;
        return true;
    }
    bool checkRowise(vector<vector<char>>& board, int row)
    {
        vector<bool> occurred(COL + 1, false);
        for (int c = 0; c < COL; ++c)
        {
            if (board[row][c] != EMPTY)
            {
                int num = board[row][c] - '0';
                if (occurred[num])
                    return false;
                occurred[num] = true;
            }
        }
        return true;
    }
    bool checkColumnwise(vector<vector<char>>& board, int col)
    {
        vector<bool> occurred(ROW + 1, false);
        for (int r = 0; r < ROW; ++r)
        {
            if (board[r][col] != EMPTY)
            {
                int num = board[r][col] - '0';
                if (occurred[num])
                    return false;
                occurred[num] = true;
            }
        }
        return true;
    }
    bool checkSubboxes(vector<vector<char>>& board, int box_row, int box_col)
    {
        vector<bool> occurred(ROW + 1, false);
        for (int r = box_row * ROW_PER_BOX, row_boundary = (box_row + 1) * ROW_PER_BOX; r < row_boundary; ++r)
        {
            for (int c = box_col * COL_PER_BOX, col_boundary = (box_col + 1) * COL_PER_BOX; c < col_boundary; ++c)
            {
                if (board[r][c] != EMPTY)
                {
                    int num = board[r][c] - '0';
                    if (occurred[num])
                        return false;
                    occurred[num] = true;
                }
            }
        }
        return true;
    }
};