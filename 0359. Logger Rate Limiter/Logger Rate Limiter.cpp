class Logger {
private:
    unordered_map<string, int> mp;
    const int separate_time = 10;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) != mp.end())
        {
            if (mp[message] + separate_time > timestamp)
                return false;
        }
        mp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */