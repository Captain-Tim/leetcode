class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur_str;
        vector<string> res;
        dfs(n, 0, 0, cur_str, res);
        return res;
    }
    void dfs(int n, int left, int right, string& cur_str, vector<string>& res)
    {
        if (right == n)
        {
            res.push_back(cur_str);
            return;
        }
        if (left < n)
        {
            cur_str.push_back(LEFT_PAR);
            dfs(n, left + 1, right, cur_str, res);
            cur_str.pop_back();
        }
        if (left > right)
        {
            cur_str.push_back(RIGHT_PAR);
            dfs(n, left, right + 1, cur_str, res);
            cur_str.pop_back();
        }
    }
private:
    const char LEFT_PAR = '(';
    const char RIGHT_PAR = ')';
};