#include <iostream>
#include <cmath>
using namespace std;

// Helper function
int getAllWaysHelper(int remainingSum, int power, int base)
{
    // calculate power
    int result = pow(base, power);

    if (remainingSum == result)
        return 1;

    if (remainingSum < result)
        return 0;

    // Two recursive calls one to include current base's power in sum another to exclude
    int x = getAllWaysHelper(remainingSum - result, power, base + 1);
    int y = getAllWaysHelper(remainingSum, power, base + 1);

    return x + y;
}

int getAllWays(int sum, int power)
{
    return getAllWaysHelper(sum, power, 1);
}

// Driver Code.
int main()
{
    int x = 10, n = 2;
    cout << getAllWays(x, n);
    return 0;
}