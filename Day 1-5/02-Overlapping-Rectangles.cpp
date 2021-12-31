// Problem Link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/#

// Time Complexity: O(1) as the code doesn't have any loop or recursion.

class Solution
{
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        // If one rectangle is on left side of other
        if (L1[0] > R2[0] || L2[0] > R1[0])
            return false;

        // If one rectangle is above other
        if (R1[1] > L2[1] || R2[1] > L1[1])
            return false;

        return true;
    }
};