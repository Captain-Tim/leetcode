class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (const int& i : nums1)
            ++mp[i];
        vector<int> res;
        for (const int& i : nums2)
        {
            if (mp[i] > 0)
            {
                res.push_back(i);
                --mp[i];
            }
        }
        return res;
    }
};