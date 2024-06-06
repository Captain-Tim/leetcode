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
        int left = 0;
        int right = reader.length() - 1;
        while (left < right)
        {
            int lower_mid = left + (right - left) / 2;
            int upper_mid = left + (right - left + 1) / 2;
            int compare_result = reader.compareSub(left, lower_mid, upper_mid, right);
            if (compare_result == 1)
                right = lower_mid;
            else if (compare_result == -1)
                left = upper_mid;
            else
                return upper_mid;
        }
        return left;
    }
};