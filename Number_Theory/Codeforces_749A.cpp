
// Given a positive integer n represent it as a sum of maximum
// possible number of prime numbers

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << '\n';
        for (int i = 1; i <= (n / 2); i++)
        {
            cout << 2 << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << ((n - 3) / 2) + 1 << '\n';
        for (int i = 1; i <= ((n - 3) / 2); i++)
        {
            cout << 2 << " ";
        }
        cout << 3 << '\n';
    }
}