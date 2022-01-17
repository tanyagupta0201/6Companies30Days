// Problem Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

class Solution
{
public:
    void GenerateParenthesis(int n, int open, int close, string s, vector<string> &ans)
    {
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;
        }

        // At any index i in the generation of the string s, we can put an open parentheses only if its count until that time is less than n.
        if (open < n)
        {
            GenerateParenthesis(n, open + 1, close, s + "(", ans);
        }

        // At any index i in the generation of the string s, we can put a closed parentheses only if its count until that time is less than the count of open parentheses.
        if (close < open)
        {
            GenerateParenthesis(n, open, close + 1, s + ")", ans);
        }
    }

    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        GenerateParenthesis(n, 0, 0, "", ans);
        return ans;
    }
};