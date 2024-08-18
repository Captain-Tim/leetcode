class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int LETTER_NUM = 26;
        vector<int> common_char_num(LETTER_NUM, INT_MAX);
        for (string& s : words)
        {
            vector<int> letters(LETTER_NUM, 0);
            for (char c : s)
                ++letters[c - 'a'];
            for (int i = 0; i < LETTER_NUM; ++i)
                common_char_num[i] = min(common_char_num[i], letters[i]);
        }
        vector<string> res;
        for (int i = 0; i < LETTER_NUM; ++i)
            res.insert(res.end(), common_char_num[i], string(1, 'a' + i));
        return res;
    }
};