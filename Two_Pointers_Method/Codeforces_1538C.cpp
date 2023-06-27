#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<int> &v, int n)
{
    int l = 0, r = v.size() - 1;
    ll ans = 0;
    while (l < r)
    {
        if (v[l] + v[r] > n)
        {
            r--;
        }
        else
        {
            ans += r - l;
            l++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = solve(a, r) - solve(a, l - 1);
        cout << ans << '\n';
    }
}