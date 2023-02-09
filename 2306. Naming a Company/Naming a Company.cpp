class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        const int alphabet_num = 26;
        vector<unordered_set<string>> groups(alphabet_num);
        for (const string& s : ideas)
            groups[s[0] - 'a'].insert(s.substr(1));
        long long res = 0;
        for (int i = 0; i < alphabet_num; ++i)
        {
            if (groups[i].empty())
                continue;
            for (int j = i + 1; j < alphabet_num; ++j)
            {
                if (groups[j].empty())
                    continue;
                int intersection = 0;
                for (const string& s : groups[i])
                    if (groups[j].find(s) != groups[j].end())
                        ++intersection;
                res += (groups[i].size() - intersection) * (groups[j].size() - intersection);
            }
        }
        return res << 1;
    }
};