class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        using pid = pair<int, double>;
        vector<pid> pos_time;
        for (int i = 0; i < position.size(); ++i)
            pos_time.push_back({position[i], (double) (target - position[i]) / speed[i]});
        auto cmp = [](pid& a, pid& b)
        {
            return a.first > b.first;
        };
        sort(pos_time.begin(), pos_time.end(), cmp);
        stack<double> stk;
        for (pid& p : pos_time)
        {
            if (stk.empty() || stk.top() < p.second)
                stk.push(p.second);
        }
        return stk.size();
    }
};