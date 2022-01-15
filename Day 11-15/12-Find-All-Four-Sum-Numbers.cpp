// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

class Solution
{
public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;

        if (arr.empty())
            return ans;

        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            int target3 = target - arr[i];

            for (int j = i + 1; j < n; j++)
            {
                int target2 = target3 - arr[j];

                int front = j + 1;
                int back = n - 1;

                while (front < back)
                {
                    int twoSum = arr[front] + arr[back];

                    if (twoSum < target2)
                        front++;
                    else if (twoSum > target2)
                        back--;
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0] = arr[i];
                        quad[1] = arr[j];
                        quad[2] = arr[front];
                        quad[3] = arr[back];
                        ans.push_back(quad);

                        // Processing the duplicates of number 3
                        while (front < back && arr[front] == quad[2])
                            front++;

                        // Processing the duplicates of number 4
                        while (front < back && arr[back] == quad[4])
                            back--;
                    }
                }
                // Processing the duplicates of number 2
                while (j + 1 < n && arr[j + 1] == arr[j])
                    j++;
            }
            // Processing the duplicates of number 1
            while (i + 1 < n && arr[i + 1] == arr[i])
                i++;
        }
        return ans;
    }
};