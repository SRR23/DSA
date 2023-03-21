
// You have an array a1,a2,…,an. Answer q queries of the following form:

// If we change all elements in the range al,al+1,…,ar of the array to k, will the sum
// of the entire array be odd?

// Note that queries are independent and do not affect future queries.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> pref(n + 1);
    cin >> a[1];
    pref[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for (ll i = 0; i < q; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll sum = 0;
        sum = pref[n] + (r - l + 1) * k - (pref[r] - pref[l] + a[l]);

        if (sum % 2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}