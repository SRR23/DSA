
// The problem statement is really simple. You are to write
// all primes less than 10^8

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e8;
bitset<N> is_prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 2; i <= N; i++)
    {
        is_prime[i] = true;
    }
    for (ll i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    vector<ll> v;
    v.push_back(2);
    for (ll i = 3; i <= N; i += 2)
    {
        if (is_prime[i])
        {
            v.push_back(i);
        }
    }
    for (ll i = 0; i < v.size(); i += 100)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}