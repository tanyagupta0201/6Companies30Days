// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

/* 
    1. Add steps till we reach target.
    2. If the target is surpassed: Add steps until we can subtract 2 * K steps to subtract that makes us reach target ((sum - target) % 2 == 0)
*/

class Solution
{
public:
    int minSteps(int target)
    {
        int sum = 0, steps = 0;

        if (target == 0)
            return 0;

        target = abs(target);

        while (sum < target || (sum - target) % 2 != 0)
        {
            sum += steps;
            steps++;
        }

        return steps - 1;
    }
};
