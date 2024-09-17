class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            int cur_temp = temperatures[i];
            int days = i + 1;
            
            while (temperatures[i] >= temperatures[days] && res[days] != 0)
                days += res[days];
            res[i] = (temperatures[i] >= temperatures[days]) ? 0 : days - i;
        }
        return res;
    }
};