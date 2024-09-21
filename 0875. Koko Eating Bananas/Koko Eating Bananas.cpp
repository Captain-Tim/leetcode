class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int require_hours = 0;
            for (int i : piles)
                require_hours += ceil((double) i / mid);
            if (require_hours > h)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};