class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_idx = s.size() - 1;
        int t_idx = t.size() - 1;
        while (s_idx >= 0 || t_idx >= 0)
        {
            char s_char = GetChar(s, s_idx);
            char t_char = GetChar(t, t_idx);
            if (s_char != t_char)
                return false;
            --s_idx;
            --t_idx;
        }
        return true;
    }
private:
    char GetChar(string& str, int& idx)
    {
        int sharp_num = 0;
        while (idx >= 0)
        {   
            if (str[idx] == SHARP)
                ++sharp_num;
            else if (sharp_num)
                --sharp_num;
            else
                return str[idx];
            --idx;
        }
        return ' ';
    };
    const char SHARP = '#';
};
