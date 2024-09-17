class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        using pii = pair<int, int>;
        stack<pii> stk;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!stk.empty() && stk.top().first < temperatures[i])
            {
                res[stk.top().second] = (i - stk.top().second); 
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return res;
    }
};