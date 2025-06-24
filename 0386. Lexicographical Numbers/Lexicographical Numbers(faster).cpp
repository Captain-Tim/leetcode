class Solution {
public:
    vector<int> lexicalOrder(int n) {
        const int DECIMAL = 10;
        vector<int> res;
        int cur_num = 1;
        while (res.size() < n)
        {
            res.push_back(cur_num);
            if (cur_num * DECIMAL <= n)
                cur_num *= DECIMAL;
            else
            {
                // reach the bottom level
                while (cur_num != n && cur_num % DECIMAL != (DECIMAL - 1))
                {
                    ++cur_num;
                    res.push_back(cur_num);
                }

                // go back to the upper level   
                while (cur_num % DECIMAL == (DECIMAL - 1) || cur_num == n)
                    cur_num /= DECIMAL;
                ++cur_num;
            }
        }
        return res;
    }
};
