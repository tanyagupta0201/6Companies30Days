// Problem Link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

class Solution
{
public:
    // DP[val][diff]
    int lengthOfLongestAP(int a[], int n)
    {
        if (n <= 2)
            return n;

        vector<unordered_map<int, int>> dp(n);

        int maxLen = 2; // there will be atleast 2 values which will be having common difference

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = a[j] - a[i];

                // if the diff is found again with the same ending number we can increase the length of the sequence else max length remains 2
                if (dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else
                {
                    dp[j][diff] = 2;
                }

                maxLen = max(maxLen, dp[j][diff]);
            }
        }
        return maxLen;
    }
};
