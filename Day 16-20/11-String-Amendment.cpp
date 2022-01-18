// Problem Link: https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1

class Solution
{
public:
    string amendSentence(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isupper(s[i]))
            {
                s[i] = tolower(s[i]);

                if (i != 0)
                {
                    ans += " ";
                }
            }
            ans += s[i];
        }
        return ans;
    }
};
