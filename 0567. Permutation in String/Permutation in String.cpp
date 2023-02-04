class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        const int alphabet_num = 26;
        vector<int> letters(alphabet_num, 0);
        for (const char& c : s1)
            ++letters[c - 'a'];
        int diff = 0;
        for (const int& i : letters)
            if (i)
                ++diff;
        for (int i = 0; i < s2.size(); ++i)
        {
            int push_idx = s2[i] - 'a';
            --letters[push_idx];
            if (letters[push_idx] == 0)
                --diff;
            else if (letters[push_idx] == -1)
                ++diff;
            if (i >= s1.size())
            {
                int pop_idx = s2[i - s1.size()] - 'a';
                ++letters[pop_idx];
                if (letters[pop_idx] == 0)
                    --diff;
                else if (letters[pop_idx] == 1)
                    ++diff;
            }
            if (diff == 0)
                return true;
        }
        return false;
    }
};