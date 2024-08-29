class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        
        stack<char> stk;
        for (char c : s)
        {
            if (!mp.count(c))
                stk.push(c);
            else
            {
                if (stk.empty() || stk.top() != mp[c])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};