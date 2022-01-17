// Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int currSum = 0, i = 0;
        int right = n - 1, left = 0;

        while (left <= right)
        {
            currSum += arr[i];

            if (currSum == s)
            {
                return {left + 1, i + 1};
            }

            if (currSum > s)
            {
                while (currSum > s)
                {
                    currSum -= arr[left];
                    left++;

                    if (currSum == s)
                    {
                        return {left + 1, i + 1};
                    }
                }
            }
            i++;
        }

        return {-1};
    }
};