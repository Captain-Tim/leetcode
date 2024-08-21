class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for (string& s : strs)
            encoded += to_string(s.size()) + "." + s;
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        for (int i = 0; i < s.size();)
        {
            string num;
            while (s[i] != '.')
            {
                num += s[i];
                ++i;
            }
            ++i;
            int size = stoi(num);
            string str;
            while (str.size() < size)
                str.push_back(s[i++]);
            decoded.push_back(str);
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));