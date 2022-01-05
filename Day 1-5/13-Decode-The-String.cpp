// Problem Link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution
{
public:
    string decodeString(string &s, int &i)
    {
        string result;
        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                    k = k * 10 + s[i++] - '0'; // we are finding the number(covering all the continous digits)
                i++;                           // as we need to skip the opening bracket

                // Recursively calling the string present after the opening bracket
                string r = decodeString(s, i);

                // append the string k times
                while (k-- > 0)
                    result += r;
                i++; // as we need to skip the closing bracket
            }
            else
                // if the digit is not encountered simply append the string
                result += s[i++];
        }
        return result;
    }
    string decodedString(string s)
    {
        int i = 0;
        return decodeString(s, i);
    }
};