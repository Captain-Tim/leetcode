class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combinations;
        dfs(candidates, 0, target, combinations, res);
        return res;
    }
    void dfs(vector<int>& candidates, int begin_idx, int target, vector<int>& combinations, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(combinations);
            return;
        }
        else if (target < 0)
            return;
        for (int i = begin_idx; i < candidates.size() && target >= candidates[i]; ++i)
        {
            target -= candidates[i];
            combinations.push_back(candidates[i]);
            dfs(candidates, i + 1, target, combinations, res);
            combinations.pop_back();
            target += candidates[i];
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                ++i;
        }
    }
};