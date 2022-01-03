// Problem Link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

// Time Complexity: O(n)

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        stack<int> st;

        string ans;
        int num = 1;

        // Incase of D just push the number into the stack and increase its value
        // Incase of I push the number into the stack, increase its value and then print all the values of the stack
        for (auto it : s)
        {
            if (it == 'D')
            {
                st.push(num);
                num++;
            }
            else
            {
                st.push(num);
                num++;
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }

        // Since output has 1 number extra
        st.push(num);
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
