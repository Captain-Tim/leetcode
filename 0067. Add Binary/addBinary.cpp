class Solution {
public:
    string addBinary(string a, string b) {
        const int BINARY_BIT_MAX = 2;
        int a_idx = a.size() - 1;
        int b_idx = b.size() - 1;
        int carry = 0;
        string res;
        while (a_idx >= 0 || b_idx >= 0 || carry)
        {
            int digit_a = a_idx >= 0 ? a[a_idx] - '0' : 0;
            int digit_b = b_idx >= 0 ? b[b_idx] - '0' : 0;
            int sum = carry + digit_a + digit_b;
            if (sum >= BINARY_BIT_MAX)
            {
                carry = 1;
                sum -= BINARY_BIT_MAX;
            }
            else
                carry = 0;
            res.push_back(sum + '0');
            --a_idx;
            --b_idx;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};