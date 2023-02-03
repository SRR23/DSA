
// You are given an integer array a of length n.
// Does there exist an array b consisting of n+1 positive integers such
// that ai=gcd(bi,bi+1) for all i (1≤i≤n)?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll LCM(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v, v1, v2;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        v1.push_back(1);
        for (ll i = 0; i < v.size(); i++)
        {
            v1.push_back(v[i]);
        }
        v1.push_back(1);
        for (ll i = 1; i < v1.size(); i++)
        {
            v2.push_back(LCM(v1[i], v1[i - 1]));
        }
        ll f = 1;
        for (ll i = 0; i < n; i++)
        {
            if (__gcd(v2[i], v2[i + 1]) != v[i])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}