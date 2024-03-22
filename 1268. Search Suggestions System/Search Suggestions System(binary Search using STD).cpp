class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        const int SIZE = products.size();
        const int SUGGESTION_NUM = 3;
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix = "";
        int start = 0;
        for (char c : searchWord)
        {
            res.push_back({});
            prefix += c;
            start = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();
            for (int i = start; i < min(SIZE, start + SUGGESTION_NUM) && !products[i].compare(0, prefix.size(), prefix); ++i)
                res.back().push_back(products[i]);
        }
        return res;
    }
};