class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_h = height[left];
        int right_h = height[right];
        int res = 0;
        while (left < right)
        {
            if (left_h < right_h)
            {
                ++left;
                left_h = max(left_h, height[left]);
                res += left_h - height[left];
            }
            else
            {
                --right;
                right_h = max(right_h, height[right]);
                res += right_h - height[right];
            }
        }
        return res;
    }
};