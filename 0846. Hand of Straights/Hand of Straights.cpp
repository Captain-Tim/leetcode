class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> card_freq;
        for (int card : hand)
            ++card_freq[card];
        for (int current_card : hand)
        {
            int start_card = current_card;
            while (card_freq[start_card - 1])
                --start_card;
            for (; start_card <= current_card; ++start_card)
            {
                if (!card_freq[start_card]) // important!
                    continue;
                int start_card_freq = card_freq[start_card];
                for (int begin = start_card, end = start_card + groupSize; begin < end; ++begin)
                {
                    if (card_freq[begin] < start_card_freq)
                        return false;
                    card_freq[begin] -= start_card_freq;
                }
            }
        }
        return true;
    }
};