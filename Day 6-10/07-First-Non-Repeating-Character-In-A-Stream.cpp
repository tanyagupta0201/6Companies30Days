// Problem Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // freq array of size 26 with all positions assigned to zero
        vector<int> freq(26, 0);

        // to maintain the position of the first non-repeating character
        vector<char> v;

        string ans = "";
        int n = A.length();

        // a = 0, b = 1, c = 2, ....
        for (int i = 0; i < n; i++)
        {
            if (!freq[A[i] - 'a'])
            {
                v.push_back(A[i]);
            }

            freq[A[i] - 'a']++;
            int flag = 0;

            for (int j = 0; j < v.size(); j++)
            {
                if (freq[v[j] - 'a'] == 1)
                {
                    ans.push_back(v[j]);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
