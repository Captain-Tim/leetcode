class Solution {
public:
    bool isAnagram(string s, string t) {
        const int LETTER_NUM = 26;
        vector<int> freq(LETTER_NUM, 0);
        for (char c : s)
            ++freq[c - 'a'];
        for (char c : t)
            --freq[c- 'a'];
        for (int i : freq)
            if (i)
                return false;
        return true;
    }
};