class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur_num = 1;
        while (res.size() < n)
        {
            res.push_back(cur_num);
            if (cur_num * 10 <= n)
                cur_num *= 10;
            else
            {
                while (cur_num == n || cur_num % 10 == 9)
                    cur_num /= 10;
                ++cur_num;
            }
        }
        return res;
    }
};