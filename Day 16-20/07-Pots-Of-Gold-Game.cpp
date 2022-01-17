// Problem Link: https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

class Solution
{
public:
    int dp[500][500];

    int solve(int i, int j, vector<int> arr)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int x = arr[i] + min(solve(i + 2, j, arr), solve(i + 1, j - 1, arr));
        int y = arr[j] + min(solve(i, j - 2, arr), solve(i + 1, j - 1, arr));

        return dp[i][j] = max(x, y);
    }

    int maxCoins(vector<int> &A, int n)
    {
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, A);
    }
};