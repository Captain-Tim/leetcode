class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long sum = 0;
        long long pq_sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> required_bricks{0};
        for (int i = 1; i < heights.size(); ++i)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff <= 0)
                required_bricks.push_back(required_bricks.back());
            else
            {
                if (pq.size() < ladders)
                {
                    pq.push(diff);
                    pq_sum += diff;
                }
                else if (!pq.empty() && pq.top() < diff)
                {
                    pq_sum -= pq.top();
                    pq.pop();
                    pq_sum += diff;
                    pq.push(diff);
                }
                sum += diff;
                required_bricks.push_back(sum - pq_sum);
            }
        }
        int left = 0;
        int right = heights.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (required_bricks[mid] > bricks)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};