#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<bool> prime(N, 1);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // precalculate prime between 1 to 1e5
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    if (n > 2)
    {
        cout << 2 << '\n';
    }
    else
    {
        cout << 1 << '\n';
    }

    if (n == 1)
    {
        cout << 1 << '\n';
    }
    else if (n == 2)
    {
        cout << 1 << " " << 1 << '\n';
    }
    else
    {
        for (int i = 2; i <= n + 1; i++)
        {
            if (prime[i] == true)
            {
                cout << 2 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
        cout << '\n';
    }
}