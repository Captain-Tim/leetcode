class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int ALPHABET_NUM = 26;
        vector<int> freq(ALPHABET_NUM, 0);
        for (char c : tasks)
            ++freq[c - 'A'];
        sort(freq.begin(), freq.end(), greater<int>());
        int max_freq = freq[0];
        int max_freq_num = 0;
        for (int i : freq)
        {
            if (i == max_freq)
                ++max_freq_num;
            else
                break;
        }
        int remainding_task = tasks.size() - max_freq * max_freq_num;
        int part_num = max_freq - 1;
        int empty_slot = part_num * (n + 1 - max_freq_num);
        int idle_num = max(0, empty_slot - remainding_task);
        return tasks.size() + idle_num;
    }
};