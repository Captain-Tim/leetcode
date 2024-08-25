class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right)
        {
            int width = right - left;
            int size = width * min(height[left], height[right]);
            res = max(res, size);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return res;
    }
};