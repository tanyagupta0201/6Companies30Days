// Problem Link: https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

// Time Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int FindPosition(int a, int b, int c)
{
    int n;
    /* c + a = If they are in a straight line, -1 first toy current child ko jaa raha hai aage nhi badh rhe hai, % b if they are in a circle*/
    n = (a + c - 1) % b;

    if (n == 0)
    {
        return b;
    }
    return n;
}

int main()
{
    // a -> number of toys
    // b -> number of kids
    // c -> starting position
    int a, b, c;
    cin >> a >> b >> c;

    cout << "The kid who gets the damaged toy is at position: " << FindPosition(a, b, c) << endl;
    return 0;
}

/*
    Output

    8 5 2
    The kid who gets the damaged toy is at position: 4
*/
