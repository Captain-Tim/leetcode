class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        const auto& smaller = s1.size() > s2.size() ? s2 : s1;
        const auto& larger = s1.size() > s2.size() ? s1 : s2;
        vector<int> res;
        for (const int& i : smaller)
            if (larger.find(i) != larger.end())
                res.push_back(i);
        return res;
    }
};