#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 5;
int spf[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; 1LL * i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = 1LL * i * i; j < N; j += i)
            {
                spf[j] = min(spf[j], i);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n;
        ll sum_divs = 1;
        while (n > 1)
        {
            int p = spf[n];
            int prime_power = 1;
            while (n % p == 0)
            {
                prime_power *= p;
                n /= p;
            }
            sum_divs *= (1LL * prime_power * p - 1) / (p - 1);
        }
        cout << sum_divs - m << '\n';
    }
}