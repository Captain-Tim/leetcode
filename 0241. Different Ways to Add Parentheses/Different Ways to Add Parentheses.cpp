class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
    vector<int>& dfs(string expression)
    {
        if (dp.count(expression) == 0)
        {
            int len = expression.size();
            vector<int> result;
            for (int i = 0; i < len; ++i)
            {
                if (operators.count(expression[i]))
                {
                    vector<int> left_res = dfs(expression.substr(0, i));
                    vector<int> right_res = dfs(expression.substr(i + 1));
                    for (int j : left_res)
                        for (int k : right_res)
                            result.push_back(op(j, k, expression[i]));
                }
            }
            dp[expression] = result.empty() ? vector<int>(1, stoi(expression)) : result;
        }
        return dp[expression];
    }
private:
    unordered_set<char> operators{'+', '-', '*'};
    unordered_map<string, vector<int>> dp;
    int op(int i, int j, char operation)
    {
        if (operation == '+')
            return i + j;
        else if (operation == '-')
            return i - j;
        else
            return i * j;
    }
};