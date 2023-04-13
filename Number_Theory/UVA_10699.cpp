
// Write a program, that computes the number of different prime
// factors in a positive integer

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll spf[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        spf[i] = i;
    }
    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
            {
                spf[j] = min(spf[j], i);
            }
        }
    }

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int m = n;
        cout << m << " ";
        int distinct_prime_factor = 0;
        while (n > 1)
        {
            int p = spf[n];
            distinct_prime_factor++;
            while (n % p == 0)
            {
                n /= p;
            }
        }
        cout << ": " << distinct_prime_factor << '\n';
    }
}