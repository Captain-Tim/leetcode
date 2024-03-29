class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int max_num = INT_MIN;
        for (int i : nums)
            max_num = max(max_num, i);
        int left = 0;
        int freq = 0;
        for (int i : nums)
        {
            if (i == max_num)
                ++freq;
            while (freq > k || nums[left] != max_num)
            {
                freq -= (nums[left] == max_num);
                ++left;
            }
            if (freq == k)
                res += left + 1;
        }
        return res;
    }
};