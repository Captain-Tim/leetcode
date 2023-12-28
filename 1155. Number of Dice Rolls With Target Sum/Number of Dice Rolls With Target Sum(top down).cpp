class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k)
            return 0;
        const int MOD = 1e9 + 7;
        vector<int> dp1(target + 1, 0);
        dp1[0] = 1;
        for (int dice_idx = 0; dice_idx < n; ++dice_idx)
        {
            vector<int> dp2(target + 1, 0);
            for (int j = dice_idx; j <= target; ++j)
            {
                if (dp1[j] == 0)
                    break;
                for (int i = 1; i <= k; ++i)
                {
                    if (j + i <= target)
                    {
                        dp2[j + i] += dp1[j];
                        dp2[j + i] %= MOD;
                    }
                    else
                        break;
                }
            }
            dp1.swap(dp2);
        }
        return dp1[target];
    }
};