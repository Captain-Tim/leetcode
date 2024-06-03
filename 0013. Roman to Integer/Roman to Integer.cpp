class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_integer_table{
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}};
        int res = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (i + 1 < s.size() && roman_integer_table[s[i + 1]] > roman_integer_table[s[i]])
                res -= roman_integer_table[s[i]];
            else
                res += roman_integer_table[s[i]];
        }
        return res;
    }
};