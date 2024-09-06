class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums)
            ++freq[i];
        vector<vector<int>> bucket(nums.size() + 1, vector<int>());
        for (auto& [value, frequency] : freq)
            bucket[frequency].push_back(value);
        vector<int> res;
        for (int i = bucket.size() - 1; res.size() < k && i >= 0; --i)
        {
            for (int val : bucket[i])
                res.push_back(val);
        }
        return res;
    }
};