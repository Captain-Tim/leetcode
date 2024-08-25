class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_highest = height[left];
        int right_highest = height[right];
        int res = 0;
        while (left < right)
        {
            if (left_highest < right_highest)
            {
                ++left;
                left_highest = max(left_highest, height[left]);
                res += left_highest - height[left];
            }
            else
            {
                --right;
                right_highest = max(right_highest, height[right]);
                res += right_highest - height[right];
            }
        }
        return res;
    }
};