class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int prev = 1;
        int prev_prev = 1;
        const int MAX_NUM = 26;
        const int MIN_NUM = 10;
        for (int i = 1, len = s.size(); i < len; ++i)
        {
            int cur = 0;
            int last_two_digit = stoi(s.substr(i - 1, 2));
            if (s[i] != '0')
                cur = prev;
            if (last_two_digit >= MIN_NUM && last_two_digit <= MAX_NUM)
                cur += prev_prev;
            
            prev_prev = prev;
            prev = cur;
        }
        return prev;
    }
};