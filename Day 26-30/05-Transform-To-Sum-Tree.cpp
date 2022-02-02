// Problem Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of nodes in left and right subtrees in the original tree
    int solve(Node *root)
    {
        if (root == NULL)
            return 0;

        int a = solve(root->left);
        int b = solve(root->right);
        int x = root->data;

        root->data = a + b; // khud sirf apne left aur right subtrees ki value se hi update hoga
        return a + b + x;   // apne parent ko toh khud ki value bhi dega yeh toh +x
    }

    void toSumTree(Node *node)
    {
        solve(node);
    }
};