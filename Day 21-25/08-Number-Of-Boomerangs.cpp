// Problem Link: https://leetcode.com/problems/number-of-boomerangs/

class Solution
{
public:
    // we have to fix a point and then find all the distance of other point from that fixed point and push it into hashmap
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;

        for (auto &i : points)
        {
            unordered_map<double, int> m;

            auto x1 = i[0];
            auto y1 = i[1];

            for (auto &j : points)
            {
                if (i == j)
                    continue;

                auto x2 = j[0];
                auto y2 = j[1];

                int xDis = abs(x1 - x2) * abs(x1 - x2);
                int yDis = abs(y1 - y2) * abs(y1 - y2);

                double finalDis = sqrt(xDis + yDis);

                m[finalDis]++;
            }

            // if more than 1 point has same distance from the fixed point
            // so we need arrange them in all possible ways
            // Applying Permutation and combination
            // if we fix the first point then how many ways to fill the second place suppose (n)
            // similarly how many ways to fill third place n-1

            for (auto &i : m)
            {
                if (i.second > 1)
                {
                    ans += (i.second * (i.second - 1));
                }
            }
        }
        return ans;
    }
};