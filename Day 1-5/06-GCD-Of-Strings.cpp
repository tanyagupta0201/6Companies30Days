// Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution
{
public:
    // the length of this GCD string will be the GCD of lengths of given two strings
    int Find_gcd(int n1, int n2)
    {
        while (n1 != n2)
        {
            if (n1 > n2)
            {
                n1 = n1 - n2;
            }
            else
            {
                n2 = n2 - n1;
            }
        }
        return n1;
    }

    string gcdOfStrings(string str1, string str2)
    {
        int l1 = str1.length();
        int l2 = str2.length();

        // First we check if gcd is even possible using (str1 + str2 == str2 + str1)
        // str1 + str2 == str2 + str1 can be true only if both the strings are made of same substring added multiple times.
        // If str1 + str2 != str2 + str1 then GCD won't exist for the strings
        if (str1 + str2 == str2 + str1)
        {
            int x = Find_gcd(l1, l2);
            // Output the first prefix of this length from either of the strings.
            return str1.substr(0, x);
        }
        return "";
    }
};
