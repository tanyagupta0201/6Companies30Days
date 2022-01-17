// Problem Link: https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/#

// Power function to calculate long powers with mod
long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1ll;

    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function for finding number of ways to create string with length N and atmost K contiguous vowels
int kvowelwords(int N, int K)
{

    long long int i, j;
    long long int MOD = 1000000007;

    // Array dp to store number of ways
    long long int dp[N + 1][K + 1] = {0};

    long long int sum = 1;
    for (i = 1; i <= N; i++)
    {

        // dp[i][0] = (dp[i-1][0]+dp[i-1][1]..dp[i-1][k])*21
        dp[i][0] = sum * 21;
        dp[i][0] %= MOD;

        // Now setting sum to be dp[i][0]
        sum = dp[i][0];

        for (j = 1; j <= K; j++)
        {
            // If j>i, no ways are possible to create a string with length i and vowel j
            if (j > i)
                dp[i][j] = 0;
            else if (j == i)
            {
                // If j = i all the character should be vowel
                dp[i][j] = power(5ll, i, MOD);
            }
            else
            {
                // dp[i][j] relation with dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1] * 5;
            }

            dp[i][j] %= MOD;

            // Adding dp[i][j] in the sum
            sum += dp[i][j];
            sum %= MOD;
        }
    }

    return sum;
}