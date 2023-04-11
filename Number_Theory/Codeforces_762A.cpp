
// You are given two integers n and k. Find k-th smallest
// divisor of n, or report that it doesn't exist

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i != (n / i))
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    if (v.size() < k)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << v[k - 1] << '\n';
    }
}