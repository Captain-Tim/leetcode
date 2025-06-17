class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int IS_START_TIME = 1;
		const int IS_END_TIME = -1;
		vector<vector<int>> time;
		
		for (vector<int>& v : intervals)
		{
			time.push_back({v[0], IS_START_TIME});
			time.push_back({v[1] + 1, IS_END_TIME});
		}
		sort(time.begin(), time.end());
		int res = 0;
		int cur_overlap_num = 0;
		for (vector<int>& v : time)
		{
			cur_overlap_num += v[1];
			res = max(res, cur_overlap_num);
		}
		return res;
    }
};
