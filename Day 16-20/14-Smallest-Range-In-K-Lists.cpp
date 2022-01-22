// Problem Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

// YouTube Link: https://youtu.be/bWowdBPkidw

class Solution
{
public:
    class element
    {

    public:
        // every element has 4 attributes
        int value;
        int index;
        int row;
        int arrsize;

        element(int val, int indexnumber, int rownumber, int arraysize)
        {
            value = val;
            index = indexnumber;
            row = rownumber;
            arrsize = arraysize;
        }
    };

    struct compare
    {
        bool operator()(element a, element b)
        {
            return a.value > b.value;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &arr)
    {

        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        priority_queue<element, vector<element>, compare> q;
        int k = arr.size();
        int low, high;
        for (int i = 0; i < k; ++i)
        {
            q.push(element(arr[i][0], 0, i, arr[i].size()));
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i][0]);
        }

        while (!q.empty())
        {
            element temp = q.top();
            q.pop();
            int maybeminimum = temp.value;
            if (range > mx - maybeminimum)
            {
                mn = maybeminimum;
                range = mx - mn;
                low = mn;
                high = mx;
            }

            if (temp.index == temp.arrsize - 1)
                break;

            temp.index += 1;
            q.push(element(arr[temp.row][temp.index], temp.index, temp.row, arr[temp.row].size()));
            mx = max(mx, arr[temp.row][temp.index]);
        }

        vector<int> v{low, high};
        return v;
    }
};
