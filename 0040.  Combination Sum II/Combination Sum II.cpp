class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur_combination;
        dfs(candidates, target, 0, cur_combination, res);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start_idx, vector<int>& cur_combination, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(cur_combination);
            return;
        }
        for (int i = start_idx; i < candidates.size(); ++i)
        {
            if (target - candidates[i] < 0)
                return;
            cur_combination.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, cur_combination, res);
            cur_combination.pop_back();
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                ++i;
        }
    }
};