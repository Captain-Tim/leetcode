class Solution {
public:
    bool isHappy(int n) {
        const int decimal = 10;
        unordered_set<int> trace;
        while (n != 1)
        {
            if (trace.find(n) != trace.end())
                return false;
            trace.emplace(n);
            int new_n = 0;
            while (n)
            {
                int unit_digit = n % decimal;
                new_n += unit_digit * unit_digit;
                n /= decimal;
            }
            n = new_n;
        }
        return true;
    }
};