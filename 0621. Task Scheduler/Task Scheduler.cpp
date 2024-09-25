class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int LETTER_NUM = 26;
        vector<int> freq(LETTER_NUM, 0);
        for (char c : tasks)
            ++freq[c - 'A'];
        sort(freq.begin(), freq.end(), greater<int>());
        int max_freq = freq[0];
        int num_max_freq = 0;
        for (int i = 0; i < freq.size() && freq[i] == max_freq; ++i)
            ++num_max_freq;
        int other_tasks = tasks.size() - num_max_freq * max_freq;
        int empty_slot = (n + 1 - num_max_freq) * (max_freq - 1);
        int idle_slot = max(0, empty_slot - other_tasks);
        return tasks.size() + idle_slot;
    }
};