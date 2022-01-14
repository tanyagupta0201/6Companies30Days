// Problem Link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

vector<string> generate(int n)
{
    vector<string> ans;
    string str = "";

    for (int i = 1; i <= n; i++)
    {
        int num = i;

        while (num)
        {
            int rem = num % 2;
            str = to_string(rem) + str;
            num = num / 2;
        }

        ans.push_back(str);
        str = "";
    }
    return ans;
}