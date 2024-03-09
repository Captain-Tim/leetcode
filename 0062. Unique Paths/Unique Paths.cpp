class Solution {
public:
    int uniquePaths(int m, int n) {
        // the solution of the grid with m by n is the same as the one with size n by m
        // therefore, we choose the smaller column in order to minimize the space complexity
        if (n > m)
            swap(m, n);
        vector<int> cur_row(n, 0);
        // initial position
        cur_row[0] = 1;
        for (int r = 0; r < m; ++r)
            for (int c = 1; c < n; ++c)
                cur_row[c] += cur_row[c - 1];
        return cur_row.back();
    }
};