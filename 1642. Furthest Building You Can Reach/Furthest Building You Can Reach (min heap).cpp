class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < heights.size(); ++i)
        {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0)
            {
                pq.push(diff);
                if (pq.size() > ladders) // if we run out of ladders, we will need to use bricks
                {
                    bricks -= pq.top();
                    pq.pop();
                    if (bricks < 0) // neither ladders nor bricks are enough, we have reached the furthest building
                        return i - 1;
                }
            }
        }
        return heights.size() - 1;
    }
};