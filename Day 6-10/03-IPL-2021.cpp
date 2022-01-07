// Problem Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#

// Time Complexity: O(n)
// Space Complexity: O(k)

/*
    Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of our present window size.
    If so, we need to pop that out. Also, we need to check from the rear that the element present is smaller than the incoming element.
    If yes, there’s no point storing them and hence we pop them out. Finally, the element present at the front would be our largest element.
*/

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // it will store the indices of the elements in decreasing order
        deque<int> dq;

        // to store maximum of each subarray of size k.
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            // will remove the indices which are out of bound
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // if the last element present in the deque is greater than the current element then simply push the current element
            // if the last element present in the deque is smaller than the current element then pop all the elements which are smaller than it and then push the current element
            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();

            dq.push_back(i);

            // before moving to the next subarray store the largest element of the current subarray in the ans
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};