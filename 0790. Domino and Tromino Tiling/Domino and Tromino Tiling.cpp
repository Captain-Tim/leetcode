class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        int prev = 1;
        int prev_prev = 0;
        int prev_protrude = 0;
        while (n)
        {
            int cur = (prev + prev_prev) % MOD + (prev_protrude * 2) % MOD;
            int cur_protrude = (prev_prev + prev_protrude) % MOD;
            cur %= MOD;
            prev_prev = prev;
            prev = cur;
            prev_protrude = cur_protrude;
            --n;
        }
        return prev;
    }
};