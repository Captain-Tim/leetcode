class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = s.size(), prev = 0; i >= 0; --i)
        {
            int cur = r_to_i[s[i]];
            res += cur >= prev ? cur : -cur;
            prev = cur;
        }
        return res;
    }
private:
    unordered_map<char, int> r_to_i{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};
