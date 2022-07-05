// Problem Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

class Solution{
    public:
    // simple DFS
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
    string findOrder(string dict[], int n, int k) 
    {
        // code here
        // create an adjacency list according to the order of the alphabets
        vector<vector<int>> adj(k);
        for(int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            for(int j = 0; j < min(s1.length(), s2.length()); j++)
            {
                if(s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // Now DFS Topological sort starts
        stack<int> st;
        vector<int> vis(k, 0);
        
        for(int i = 0; i < k; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        
        // store the final order in ans 
        string ans = "";
        while(!st.empty())
        {
            ans += st.top() + 'a';
            st.pop();
        }
        
        return ans;
    }
};
