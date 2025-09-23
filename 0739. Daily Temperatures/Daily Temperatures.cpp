class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            int next_warmer_day = i + 1;            
            while (temperatures[i] >= temperatures[next_warmer_day] && res[next_warmer_day] != 0)
                next_warmer_day += res[next_warmer_day];
            if (temperatures[i] < temperatures[next_warmer_day])
                res[i] = next_warmer_day - i;
        }
        return res;
    }
};
