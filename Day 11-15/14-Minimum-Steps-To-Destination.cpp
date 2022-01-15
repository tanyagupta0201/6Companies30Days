// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

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