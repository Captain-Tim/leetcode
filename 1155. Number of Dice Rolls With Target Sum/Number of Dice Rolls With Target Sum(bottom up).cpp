class Solution {
private:
        const int MODULO = 1e9 + 7;
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        for (int i = 1, boundary = min(target, k); i <= boundary; ++i)
            dp[1][i] = 1;
        return findCombinations(n, k, target, dp);        
    }
    int findCombinations(int n, int k, int target, vector<vector<int>>& dp)
    {
        if (n <= 0 || target <= 0 || target > k * n)
            return 0;
        if (dp[n][target] == -1)
        {
            int value = 0;
            for (int i = 1; i <= k; ++i)
            {
                value += findCombinations(n - 1, k, target - i, dp);
                value %= MODULO;
            }
            dp[n][target] = value;
        }
        return dp[n][target];
    }
};