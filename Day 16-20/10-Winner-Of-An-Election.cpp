// Problem Link: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        map<string, int> m;
        vector<string> ans;
        string winner = "";
        int maxVote = 0;

        for (int i = 0; i < n; i++)
            m[arr[i]]++;

        for (auto i : m)
        {

            if (i.second > maxVote)
            {
                winner = i.first;
                maxVote = i.second;
            }
        }
        ans.push_back(winner);
        ans.push_back(to_string(maxVote));
        return ans;
    }
};