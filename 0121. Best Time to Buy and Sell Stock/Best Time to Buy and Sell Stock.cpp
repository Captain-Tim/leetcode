class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int lowest_price = INT_MAX;
        for (const int& i : prices)
        {
            lowest_price = min(lowest_price, i);
            res = max(res, i - lowest_price);
        }
        return res;
    }
};