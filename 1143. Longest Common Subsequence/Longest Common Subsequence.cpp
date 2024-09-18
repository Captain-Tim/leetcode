class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        if (size1 < size2)
            return longestCommonSubsequence(text2, text1);
        vector<int> prev(size2 + 1, 0);
        vector<int> cur(size2 + 1, 0);
        for (int i = 0; i < size1; ++i)
        {
            for (int j = 0; j < size2; ++j)
                cur[j + 1] = (text1[i] == text2[j]) ? prev[j] + 1 : max(prev[j + 1], cur[j]);
            prev.swap(cur);
        }
        
        return prev.back();
    }
};