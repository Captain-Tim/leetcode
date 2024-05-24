class Solution {
public:
    bool isPalindrome(string s) {
        /* pseudo code
        create a function checkAlNum() to check whether a char is alphanumeric or not
        left = 0
        right = length of s - 1
        while (left < right)
        {
            find a valid char pointed by left
            find a valid char pointed by right
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
        */
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !checkAlNum(s[left]))
                ++left;
            while (left < right && !checkAlNum(s[right]))
                --right;
            if (toUpperCase(s[left]) == toUpperCase(s[right]))
            {
                ++left;
                --right;
            }
            else
                return false;
        }
        return true;
    }
private:
    const int ASCII_UPPER_LOWER_DIFF = 32;
    bool checkAlNum(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char toUpperCase(char c)
    {
        return (c >= 'a' && c <= 'z') ? c - ASCII_UPPER_LOWER_DIFF : c;    
    }
};