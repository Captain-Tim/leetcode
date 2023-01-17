class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int acc_one = 0;
        int res = 0;
        for (const char& c : s)
        {
            if (c == '1')
                ++acc_one;
            else
                res = min(res + 1, acc_one);
        }
        return res;
    }
};