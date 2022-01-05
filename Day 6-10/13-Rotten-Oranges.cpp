// Problem Link: https://leetcode.com/problems/rotting-oranges/

// Time Complexity: O(n * n)
// Space Complexity: O(n * n)

int orangesRotting(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;

    /* m = number of rows, n = number of columns, total = total number of oranges present in matrix, minutes = to count number of minutes, c = how many oranges are rottened by me */
    int m = grid.size(), n = grid[0].size(), days = 0, total = 0, cnt = 0;

    queue<pair<int, int>> rotten; // to insert all the rotten oranges

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // count total number of oranges
            if (grid[i][j] != 0)
                total++;

            // push the rotten oranges inside the queue
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    // directions- right, left, down, up
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty())
    {
        int k = rotten.size(); // number of rotten oranges
        cnt += k;

        while (k--)
        {
            /* front function gives the oldest element present in the queue */
            int x = rotten.front().first, y = rotten.front().second;

            rotten.pop(); // remove the first element from the queue and check its adjacent places

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }

        if (!rotten.empty())
            days++;
    }

    // if all the oranges are rotten by me(total == cnt) then return minutes otherwise -1
    return total == cnt ? days : -1;
}
