// Problem Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/#

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        int maxElement = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= maxElement)
            {
                ans.push_back(a[i]);
                maxElement = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
