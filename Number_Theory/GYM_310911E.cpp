
// Given an array of n integers. Print the values of lpf(a), gpf(a)
// distinct_pf(a), total_pf(a), nmbr_divs(a), sum_divs(a).

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
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

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << spf[x] << " ";
        int gpf = 0;
        int distinct_pf = 0;
        int total_pf = 0;
        int nmbr_divs = 1;
        ll sum_divs = 1;
        while (x > 1)
        {
            int p = spf[x];
            gpf = max(gpf, p);
            distinct_pf++;

            int power_k = 0;
            int prime_power = 1;
            while (x % p == 0)
            {
                total_pf++;
                power_k++;
                prime_power *= p;
                x /= p;
            }
            nmbr_divs *= (power_k + 1);
            sum_divs *= (1LL * prime_power * p - 1) / (p - 1);
        }
        cout << gpf << " ";
        cout << distinct_pf << " ";
        cout << total_pf << " ";
        cout << nmbr_divs << " ";
        cout << sum_divs << '\n';
    }
}