// Problem Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#

string encode(string str)
{
    int val = 1;
    string ans = "";

    int len = str.length();

    char prev = str[0];

    for (int i = 1; i < len; i++)
    {
        if (str[i] == prev)
        {
            val++;
        }
        else
        {
            cout << str[i - 1] << val;
            val = 1;
        }

        prev = str[i];
    }

    ans = prev + to_string(val);
    return ans;
}