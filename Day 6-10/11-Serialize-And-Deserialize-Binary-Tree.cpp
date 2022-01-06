// Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";

        string s = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode == NULL)
                s.append("#,");
            else
                s.append(to_string(currNode->val) + ',');

            if (currNode != NULL)
            {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream s(data); // used for breaking the data
        string str;           // used for storing individual node

        // The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered.
        getline(s, str, ',');

        // the stoi() function converts a string to an integer value.
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // For the left node of the root
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // For the right node of the root
            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
