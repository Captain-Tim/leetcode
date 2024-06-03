class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_idx = s.size() - 1;
        int t_idx = t.size() - 1;
        while (s_idx >= 0 || t_idx >= 0)
        {
            moveToNextValidIdx(s, s_idx);
            moveToNextValidIdx(t, t_idx);
            if (s_idx >= 0 && t_idx >= 0)
            {
                if (s[s_idx] != t[t_idx])
                    return false;
                --s_idx;
                --t_idx;
            }
            else if (s_idx >= 0 != t_idx >= 0)
                return false;
        }
        return true;
    }
    void moveToNextValidIdx(string& str, int& idx)
    {
        int sharp_num = 0;
        while (idx >= 0)
        {
            if (str[idx] == '#')
                ++sharp_num;
            else
            {
                if (sharp_num)
                    --sharp_num;
                else
                    return;
            }
            --idx;
        }
        return;
    }
};