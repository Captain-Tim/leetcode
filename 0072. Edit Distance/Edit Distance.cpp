class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        for (int i = 0; i < l2; ++i)
            dp.back()[i] = l2 - i;
        for (int i = 0; i < l1; ++i)
            dp[i].back() = l1 - i;
        dp.back().back() = 0;
        for (int i = l1 - 1; i >= 0; --i)
        {
            for (int j = l2 - 1; j >= 0; --j)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                {
                    int insert = dp[i][j + 1];
                    int del = dp[i + 1][j];
                    int replace = dp[i + 1][j + 1];
                    dp[i][j] = 1 + min(insert, min(del, replace));
                }
            }
        }
        return dp[0][0];
    }
};