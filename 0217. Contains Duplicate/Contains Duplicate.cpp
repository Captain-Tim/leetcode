class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (const int& i : nums)
        {
            if (s.find(i) != s.end())
                return true;
            s.emplace(i);
        }
        return false;
    }
};