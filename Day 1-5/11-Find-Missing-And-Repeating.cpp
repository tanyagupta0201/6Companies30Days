/*
    1) Approach 1: Count Sort

    We can make a frequency array and initialise all values to zero and then traverse through the entire array and increase account in the frequency array.
    One element will have zero frequency this will be the missing number while one element will have frequency greater than one which will be the repeating number.

    Time complexity: O(2N)
    [O(N) as we are traversing through the array + O(N) now we are traversing through the frequency array to find the missing and repeating element.]

    Space Complexity: O(N)


    2) Approach 2: Using Maths
    Time Complexity: O(N)
    Space Complexity: O(1)

    convert the given problem into mathematical equations. Since we have two variables where one is missing and one is repeating,
    we can form two linear equations and then solve for the values of these two variables using the equations.

    Assume the missing number to be X and the repeating one to be Y.
    Now since the numbers are from 1 to N in the array arr[]. Let’s calculate sum of all integers from 1 to N and sum of squares of all integers from 1 to N. These can easily be done using mathematical formulae.

    Sum of all elements from 1 to N:   S = N*(N+1)/2 ---- equation 1
    Sum of squares of all elements from 1 to N:  P = N(N+1)(2N+1)/6. ----- equation 2

    Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.
    s1 = Sum of all elements of the array. —– equation 3
    P1 = Sum of squares of all elements of the array. ——– equation 4
    Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y)
    Therefore,

    (X-Y) = s – s1 = s’
    Similarily, X^2 – Y^2 = P – P1 = P’
    or, (X + Y)(X – Y) = P’
    or, (X + Y)*s’ = P’
    or, X + Y = P’/s’
    we have the two equations we needed:
    (X – Y) = s’
    (X + Y) = P’/s’
    We can use the two equations to solve and find values for X and Y respectively.
    here s and P can be large so take long long int data type.

    CODE:

    vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;

    for(int i=0;i<A.size(); i++){
        S -= (long long int)A[i];
        P -= (long long int)A[i]*(long long int)A[i];
    }

    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}

*/

class Solution
{
public:
    vector<int> Solution::repeatedNumber(const vector<int> &arr)
    {
        int x = 0; // missing number
        int y = 0; // repeated number
        int xor1 = 0;

        /* (all elements of array) XOR (all numbers from 1 to n) = Will give 2 numbers- missing and repeated number */

        // XOR of all the array elements
        for (int i = 0; i < n; i++)
        {
            xor1 = xor1 ^ arr[i];
        }

        // XOR the previous result with all the numbers from 1 to n
        for (int i = 1; i <= n; i++)
        {
            xor1 = xor1 ^ i;
        }

        // Now we have got x ^ y, now x is either 0 or 1 and y is either 0 or 1; as x and y are different

        // Now we will find the rightmost set bit
        // We are going to check every number of the array, the rightmost bit will be either 0 or 1, we are going to divide numbers into buckets accordingly.

        // Get the rightmost set bit in setBitNumber
        int setBitNumber;
        setBitNumber = xor1 & ~(xor1 - 1);

        for (i = 0; i < n; i++)
        {
            if (arr[i] & setBitNumber)
                /* arr[i] belongs to first set */
                x = x ^ arr[i];
            else
                /* arr[i] belongs to second set */
                y = y ^ arr[i];
        }

        // Again traverse through all the numbers from 1 to n, and classify them into 2 buckets according to the rightmost set bit
        for (i = 1; i <= n; i++)
        {
            if (i & setBitNumber)
                /* i belongs to first set */
                x = x ^ i;

            else
                /* i belongs to second set */
                y = y ^ i;
        }

        int x_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                x_count++;
        }

        if (x_count == 0)
            return {y, x};

        return {x, y};
    }
};
