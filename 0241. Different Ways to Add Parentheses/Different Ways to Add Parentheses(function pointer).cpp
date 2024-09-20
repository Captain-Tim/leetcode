class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int size = expression.size();
        dp.assign(size, vector<vector<int>>(size));
        return helper(expression, 0, expression.size() - 1);
    }
    vector<int>& helper(string& expression, int left, int right)
    {
        vector<int>& result = dp[left][right];
        if (result.empty())
        {
            for (int i = left; i <= right; ++i)
            {
                if (operations.count(expression[i]))
                {
                    vector<int>& left_res = helper(expression, left, i - 1);
                    vector<int>& right_res = helper(expression, i + 1, right);
                    for (int j : left_res)
                        for (int k : right_res)
                            result.push_back(operations[expression[i]](j, k));
                }
            }
            if (result.empty())
                result.push_back(stoi(expression.substr(left, right - left + 1)));
        }
        return result;
    }
private:
    unordered_map<char, int(*)(int, int)> operations
    {
        {'+', [](int a, int b){return a + b;}},
        {'-', [](int a, int b){return a - b;}},
        {'*', [](int a, int b){return a * b;}}
    };
    vector<vector<vector<int>>> dp;
};