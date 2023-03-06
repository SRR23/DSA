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
        int n;
        cin >> n;
        ll a[n];
        multiset<ll> ml;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                if (!ml.empty())
                {
                    auto it1 = *(ml.rbegin());
                    ans += it1;
                    auto it2 = --ml.end();
                    ml.erase(it2);
                }
            }
            else
            {
                ml.insert(a[i]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}