class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s)
        {
            if (stk.empty() || mp[c] != stk.top())
                stk.push(c);
            else
                stk.pop();
        }
        return stk.empty();
    }
private:
    unordered_map<char, char> mp{
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
};