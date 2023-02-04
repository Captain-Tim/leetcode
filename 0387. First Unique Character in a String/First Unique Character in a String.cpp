class Solution {
public:
    int firstUniqChar(string s) {
        const int num = 26;
        vector<int> occ(num, 0);
        for (const char& c : s)
            ++occ[c - 'a'];
        for (int i = 0; i < s.size(); ++i)
            if (occ[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};