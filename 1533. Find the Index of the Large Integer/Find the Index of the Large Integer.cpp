/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l = 0;
        int y = reader.length() - 1;
        while (l < y)
        {
            bool is_odd_length = (y - l + 1) % 2;
            int x = l + (y - l + 1) / 2 + is_odd_length;
            int r = l + (y - l) / 2 - is_odd_length;
            int result = reader.compareSub(l, r, x, y);
            if (result == 1)
                y = r;
            else if (result == -1)
                l = x;
            else
                return x - 1;
        }
        return l;
    }
};