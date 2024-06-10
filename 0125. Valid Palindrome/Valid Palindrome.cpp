class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isAlphanumeric(s[left]))
                ++left;
            while (left < right && !isAlphanumeric(s[right]))
                --right;
            if (toUpperCase(s[left]) != toUpperCase(s[right]))
                return false;
            ++left;
            --right;
        }
        return true;
    }
    bool isAlphanumeric(char c)
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    char toUpperCase(char c)
    {
        return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
    }
};