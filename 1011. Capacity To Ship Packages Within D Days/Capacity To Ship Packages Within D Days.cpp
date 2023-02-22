class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_cargo = 0;
        int total_weight = 0;
        for (const int& i : weights)
        {
            total_weight += i;
            max_cargo = max(i, max_cargo);
        }
        int left = max(max_cargo, total_weight / days);
        int right = max_cargo + ceil((double) total_weight / days);
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (!canConveyOnTime(weights, mid, days))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
        
    }
    bool canConveyOnTime(vector<int>& weights, int capacity, int days)
    {
        int total_days = 0;
        int cur_weight = 0;
        for (int i = 0; i < weights.size(); ++i)
        {
            int next_weight = cur_weight + weights[i];
            if (next_weight > capacity)
            {
                cur_weight = weights[i];
                ++total_days;
            }
            else if (next_weight == capacity)
            {
                cur_weight = 0;
                ++total_days;
            }
            else
                cur_weight = next_weight; 
        }
        total_days += cur_weight ? 1 : 0;
        return total_days <= days;
    }
};