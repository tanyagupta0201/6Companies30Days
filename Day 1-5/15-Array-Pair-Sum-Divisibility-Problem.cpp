// Problem Link: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

/*
    1) If length of given array is odd, return false.
       An odd length array cannot be divided into pairs.

    2) Traverse input array and count occurrences of all remainders (use (arr[i] % k)+k)%k for handling the case of negative integers as well).
       freq[((arr[i] % k)+k)%k]++

    3) Traverse input array again.
        a) Find the remainder of the current element.
        b) If remainder divides k into two halves, then there must be even occurrences of it as it forms pair with itself only.
        c) If the remainder is 0, then there must be even occurrences.
        d) Else, number of occurrences of current the remainder must be equal to a number of occurrences of "k - current remainder".
*/

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        int n = nums.size();
        // If the length of array is odd, return false
        if (n & 1)
            return false;

        unordered_map<int, int> freq; // To count the occurences of all the remainders

        // Count occurrences of all remainders
        for (auto a : nums)
            freq[((a % k) + k) % k]++; // Handles negative elements as well

        // There should be even occurences of rem = 0
        if (freq[0] % 2 == 1)
            return false;

        for (int i = 1; i < k; i++)
        {
            if (freq[i] != freq[k - i])
                return false;
        }
        return true;
    }
};