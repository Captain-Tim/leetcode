class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](string& a, string& b){
            return a + b > b + a;
        };
        vector<string> vec;
        for (int i : nums)
            vec.push_back(to_string(i));
        sort(vec.begin(), vec.end(), cmp);
        string res;
        for (string& s : vec)
            res += s;
        if (res[0] == '0')
            return "0";
        return res;
    }
};