class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev_row{triangle[0]};
		for (int i = 1; i < triangle.size(); ++i)
		{
			vector<int> cur_row(i + 1, 0);
			for (int j = 0; j < cur_row.size(); ++j)
			{
				int left = (j == 0) ? INT_MAX : prev_row[j - 1];
				int right = (j == cur_row.size() - 1) ? INT_MAX : prev_row[j];
				cur_row[j] = min(left, right) + triangle[i][j];
			}
			prev_row.swap(cur_row);
		}
		int res = INT_MAX;
		for (const int& i : prev_row)
			res = min(res, i);
		return res;
    }
};