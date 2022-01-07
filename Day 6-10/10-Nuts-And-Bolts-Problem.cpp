// Problem Link: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1#

// Time Complexity: O(n)

/*
    1. Traverse the nuts array and create a hashmap.
    2. Traverse the bolts array and search for it in hashmap.
    3. If it is found in the hashmap of nuts then this means bolts exist for that nut.
*/

class Solution
{
public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        unordered_map<char, int> hash;

        // creating a hashmap for nuts
        for (int i = 0; i < n; i++)
            hash[nuts[i]] = i;

        // searching for nuts for each bolt in hash map
        for (int i = 0; i < n; i++)
        {
            if (hash.find(bolts[i]) != hash.end())
                nuts[i] = bolts[i];
        }

        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};