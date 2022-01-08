// Problem Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#

class Solution
{
public:
    string colName(long long int n)
    {
        string res = "";

        while (n)
        {
            char c = 'A' + (n - 1) % 26; // last character
            res = c + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};