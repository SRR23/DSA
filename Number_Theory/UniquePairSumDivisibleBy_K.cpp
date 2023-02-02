
// Codeforces_1133B

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
    vector<int> v(k, 0);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[x % k]++;
    }
    ll sum = v[0] / 2;
    for (int i = 1; i <= k / 2; i++)
    {
        if (i != k - i)
        {
            sum += min(v[i], v[k - i]);
        }
        else
        {
            sum += (v[i] / 2);
        }
    }
    cout << sum * 2 << '\n';
}