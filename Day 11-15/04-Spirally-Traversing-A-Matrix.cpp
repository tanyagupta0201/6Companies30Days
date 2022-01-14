// Problem Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/#

// Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(int m, int n, vector<vector<int>> a)
{
    int direction = 0;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    vector<int> v;

    while (top <= bottom and left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                v.push_back(a[top][i]);
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                v.push_back(a[i][right]);
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(a[bottom][i]);
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                v.push_back(a[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return v;
}