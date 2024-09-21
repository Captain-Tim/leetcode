class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
    vector<int>& dfs(string expression)
    {
        if (dp.count(expression) == 0)
        {
            vector<int> res;
            for (int i = 0; i < expression.size(); ++i)
            {
                char op = expression[i];
                if (operations.count(op) == 0)
                    continue;
                vector<int>& left_vec = dfs(expression.substr(0, i));
                vector<int>& right_vec = dfs(expression.substr(i + 1));
                for (int j : left_vec)
                    for (int k : right_vec)
                        res.push_back(operations[op](j, k));
            }
            if (res.empty())
                res.push_back(stoi(expression));
            dp[expression] = res;
        }
        return dp[expression];
    }
private:
    unordered_map<string, vector<int>> dp;
    unordered_map<char, function<int(int, int)>> operations{
        {'+', [](int a, int b){return a + b;}},
        {'-', [](int a, int b){return a - b;}},
        {'*', [](int a, int b){return a * b;}}};
};