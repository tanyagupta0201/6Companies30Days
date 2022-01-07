// Problem Link: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#

// Time Complexity: O(n) where n is number of nodes in linked list

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        int c;
        Node *t;
        Node *curr = head;

        while (curr)
        {
            // Skip M nodes
            for (c = 1; c < M && curr != NULL; c++)
            {
                curr = curr->next;
            }

            // If we have reached the end of the linked list
            if (curr == NULL)
                return;

            t = curr->next;

            // Delete N nodes
            for (c = 1; c <= N && t != NULL; c++)
            {
                Node *temp = t;
                t = t->next;
                free(temp);
            }

            // Link the previous list with remaining nodes
            curr->next = t;

            // Set current pointer for next iteration
            curr = t;
        }
    }
};