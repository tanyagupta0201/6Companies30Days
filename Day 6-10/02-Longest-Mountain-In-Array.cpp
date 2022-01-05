// Problem Link: https://leetcode.com/problems/longest-mountain-in-array/

// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int res = 0;
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            int count = 1; // the length of the mountain is atleast one

            // flag variable is maintained to track if decreasing sequence exists or not because if only incresing sequence is present then this solution will give wrong output
            bool flag = false;

            // Find Increasing Sequence
            int j = i;

            while (j < n && arr[j] > arr[j - 1])
            {
                j++;
                count++;
            }

            // Find Decreasing Sequence
            // We will find Decreasing Sequence only if increasing sequence exists so i != j
            while (i != j && j < n && arr[j] < arr[j - 1])
            {
                j++;
                count++;
                flag = true;
            }

            // max of length
            if (i != j && count >= 3 && flag)
            {
                res = max(count, res);
                // we need to decrease the value of j as it will point to the next element so for the next iteration we want it to start from where we left the previous iteration
                j--;
            }

            i = j;
        }

        return res;
    }
};