// Problem Link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {

        long long int start = 0, end = 0, res = 0, p = 1;

        for (end = 0; end < a.size(); end++)
        {
            p = p * a[end];

            while (start < a.size() && p >= k)
            {
                p = p / a[start];
                start++;
            }

            if (p < k)
            {
                res += end - start + 1;
            }
        }
        return res;
    }
};