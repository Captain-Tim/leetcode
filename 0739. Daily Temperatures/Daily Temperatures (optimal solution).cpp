class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            int days = i + 1;            
            while (temperatures[i] >= temperatures[days] && res[days] != 0)
                days += res[days];
            if (temperatures[i] < temperatures[days])
                res[i] = days - i;
        }
        return res;
    }
};