#include <bits/stdc++.h>
using namespace std;

int CountSquares(int n)
{
    int squareCount = (n * (n + 1) / 2) * (2 * n + 1) / 3;
    return squareCount;
}

int main()
{
    int n;
    cin >> n;

    cout << "Number of squares: " << CountSquares(n);
    return 0;
}