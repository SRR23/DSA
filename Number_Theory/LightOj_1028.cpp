
// you have to find the number of bases where the given number
// contains at least one trailing zero. You can use any base from
// two to infinity

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 1;
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
    for (int i = 2; 1LL * i * i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = 1LL * i * i; j < N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    vector<int> v;
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            v.push_back(i);
        }
    }

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cout << "Case " << k;
        ll n;
        cin >> n;
        int divisors_cnt = 1;
        for (int i = 0; i < v.size(); i++)
        {
            int p = v[i];
            int power_p = 0;
            if (1LL * p * p > n)
            {
                break;
            }
            while (n % p == 0)
            {
                power_p++;
                n /= p;
            }
            divisors_cnt *= (power_p + 1);
        }
        if (n > 1)
        {
            int power_p = 1;
            divisors_cnt *= (power_p + 1);
        }
        cout << ": " << divisors_cnt - 1 << '\n';
    }
}