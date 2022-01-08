// Problem Link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/#

// when order does not matter.

/*
long long countWays(int m)
{
    long long ways = 0;
    for (int i = 0; i <= m; i++)
    {
        ways++;
        m--;
    }
    return ways;
}
*/

class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int m)
    {
        if (m == 1)
            return 1;

        if (m % 2 == 0)
            return 1 + countWays(m - 1);
        else
            return countWays(m - 1);
    }
};