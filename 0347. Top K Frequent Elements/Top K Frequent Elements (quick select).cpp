class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums)
            ++freq[i];
        vector<pair<int, int>> val_freq;
        for (auto& [val, f] : freq)
            val_freq.push_back({val, f});
        int left = 0;
        int right = val_freq.size() - 1;
        while (1)
        {
            int pivot_idx = partition(val_freq, left, right);
            if (pivot_idx > k - 1)
                right = pivot_idx - 1;
            else if (pivot_idx < k - 1)
                left = pivot_idx + 1;
            else
                break;
        }
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(val_freq[i].first);
        return res;
            
    }
    int partition(vector<pair<int, int>>& val_freq, int left, int right)
    {
        int mid = left + (right - left) / 2;
        int pivot_freq = val_freq[mid].second;
        for (int i = left; i <= right; )
        {
            if (val_freq[i].second > pivot_freq)
                swap(val_freq[i++], val_freq[left++]);
            else if (val_freq[i].second < pivot_freq)
                swap(val_freq[i], val_freq[right--]);
            else
                ++i;
        }
        return right;
    }
};