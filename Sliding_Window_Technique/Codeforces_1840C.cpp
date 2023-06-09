
// minimum k length er koita subarray ace, jader protita
// element q er soman ba choto.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll r = 0, l = 0, ans = 0;
        while (r < n)
        {
            if (v[r] <= q)
            {
                l++;
            }
            else
            {
                if (l >= k)
                {
                    ll x = l - k + 1;
                    ll sum = x * (x + 1) / 2;
                    ans += sum;
                }
                l = 0;
            }
            r++;
        }

        if (l >= k)
        {
            ll x = l - k + 1;
            ll sum = x * (x + 1) / 2;
            ans += sum;
        }
        cout << ans << '\n';
    }
}