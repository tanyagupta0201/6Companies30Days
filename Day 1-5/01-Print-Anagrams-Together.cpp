// Problem Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#

// Time Complexity: NKlog(K), where K is the maximum length of the string.

/* We can further optimise this problem by using hash maps where we will make an array for each string present and then compare them with each other.
   Its Time Complexity: O(n)
*/

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        // string stores the word in sorted order, vector stores the original words
        // We have taken unordered map as it is mentioned in the ques that the order does not matter, and unordered map decreases the time complexity
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < string_list.size(); i++)
        {
            // Sort each string and insert it into the bucket of the same type
            string s = string_list[i];
            sort(s.begin(), s.end());
            m[s].push_back(string_list[i]);
        }

        // We have to return in array of strings
        // Since we have to return only the second part, remove the key part
        vector<vector<string>> v;
        for (auto i : m)
        {
            v.push_back(i.second);
        }
        return v;
    }
};
