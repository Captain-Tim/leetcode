class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list2.size(); ++i)
            mp[list2[i]] = i;
        int cur_sum = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list1.size(); ++i)
        {
            if (mp.find(list1[i]) != mp.end())
            {
                int idx_sum = i + mp[list1[i]];
                if (cur_sum > idx_sum)
                {
                    cur_sum = idx_sum;
                    res = {list1[i]};
                }
                else if (cur_sum == idx_sum)
                    res.push_back(list1[i]);
            }
        }
        return res;
    }
};