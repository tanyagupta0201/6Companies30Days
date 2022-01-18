// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/#

/*
    1. Insert arr[0]
    2. if the incoming element is greater than the last element present in the array simply insert it.
    3. if the incoming element is smaller than the last element present in the array, search if it is already present in the array,
        if not then search the next greater element and replace it with the incoming element.

*/

class Solution
{
public:
    int lis(vector<int> v)
    {
        vector<int> ans;

        if (v.size() > 0)
        {
            ans.push_back(v[0]);
        }

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > ans.back())
            {
                ans.push_back(v[i]);
            }
            else
            {
                int id = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                ans[id] = v[i];
            }
        }
        return ans.size();
    }

    int minInsAndDel(int A[], int B[], int N, int M)
    {
        // Remove the extra elements from array A
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            if (binary_search(B, B + M, A[i]))
            {
                res.push_back(A[i]);
            }
        }
        return (N + M - (2 * lis(res)));
    }
};