
// we'll call a positive integer t Т-prime, if t has exactly
// three distinct positive divisors. You are given an array of n
// positive integers. For each of them determine whether it is
// Т-prime or not

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
bitset<N> is_prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        is_prime[i] = true;
    }
    for (ll i = 2; i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        int p = sqrtl(x);
        while (1LL * p * p < x)
        {
            p++;
        }
        while (1LL * p * p > x)
        {
            p--;
        }
        if ((1LL * p * p == x) && is_prime[p])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}