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
    for (int k = 1; k <= t; k++)
    {
        cout << "Case " << k << ": ";
        int P, L;
        cin >> P >> L;
        int n = P - L;
        vector<int> v;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i > L)
                {
                    v.push_back(i);
                }
                if (i != (n / i) && (n / i) > L)
                {
                    v.push_back(n / i);
                }
            }
        }
        if (v.empty())
        {
            cout << "impossible" << '\n';
        }
        else
        {
            sort(v.begin(), v.end());
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << '\n';
        }
    }
}