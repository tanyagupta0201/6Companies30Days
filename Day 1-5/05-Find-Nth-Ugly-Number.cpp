// Problem Link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        ull ugly[n]; // To store ugly numbers

        ull i2 = 0, i3 = 0, i5 = 0;
        ull nm2 = 2, nm3 = 3, nm5 = 5; // these are for next multiples of 2, 3 and 5 respectively

        ull nextUgly = 1;

        ugly[0] = 1; // First ugly number is 1

        for (int i = 1; i < n; i++)
        {
            nextUgly = min(min(nm2, nm3), nm5);

            ugly[i] = nextUgly;

            if (nextUgly == nm2)
            {
                i2++;
                nm2 = ugly[i2] * 2;
            }

            if (nextUgly == nm3)
            {
                i3++;
                nm3 = ugly[i3] * 3;
            }

            if (nextUgly == nm5)
            {
                i5++;
                nm5 = ugly[i5] * 5;
            }
        }
        return nextUgly;
    }
};