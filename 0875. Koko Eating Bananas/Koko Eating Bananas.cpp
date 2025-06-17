class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        for (int i : piles)
            right = max(right, i);
        
        int left = 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int time = 0;
            for (int i : piles)
                time += ceil( (double) i / mid);
            if (time > h)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
