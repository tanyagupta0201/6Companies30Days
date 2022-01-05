/*
    We can keep a priority queue of the 10 biggest numbers
    Iterate through the billion numbers, whenever you encounter a number greater than the smallest number in the queue
    (the head of the queue), remove the head of the queue and add the new number to the queue.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;

    vector<int> inp(n);

    for (int i = 0; i < n; i++)
        cin >> inp[i];

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        if (q.size() < 10 or inp[i] > q.top())
            q.push(inp[i]);
        while (q.size() > 10)
            q.pop();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}