// Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/#

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());

    // Take Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}