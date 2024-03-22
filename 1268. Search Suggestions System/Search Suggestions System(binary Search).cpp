class Solution {
private:
    int bs(vector<string>& products, int start, int end, string& target)
    {
        int left = start;
        int right = end;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (products[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    bool comparePrefix(string& s, string& prefix)
    {
        if (s.size() < prefix.size())
            return false;
        for (int i = 0; i < prefix.size(); ++i)
            if (s[i] != prefix[i])
                return false;
        return true;
    }
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
            start = bs(products, start, SIZE - 1, prefix);
            for (int i = start; i < min(SIZE, start + SUGGESTION_NUM) && comparePrefix(products[i], prefix); ++i)
                res.back().push_back(products[i]);
            
        }
        return res;
    }
};