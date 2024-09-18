class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int a, int b){
            string a_str = to_string(a);
            string b_str = to_string(b);
            string a_cat = a_str + b_str;
            string b_cat = b_str + a_str;
            int idx = 0;
            while (idx < a_cat.size())
            {
                if (a_cat[idx] < b_cat[idx])
                    return false;
                else if (a_cat[idx] > b_cat[idx])
                    return true;
                ++idx;
            }
            return false;
        };
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (const int i : nums)
            res += to_string(i);
        
        if (res[0] == '0') 
            return "0";
        return res;
    }
};