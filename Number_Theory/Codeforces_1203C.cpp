#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll GCD = a[0];
    for (int i = 1; i < n; i++)
    {
        GCD = __gcd(GCD, a[i]);
    }
    int cnt = 0;
    for (int i = 1; 1LL * i * i <= GCD; i++)
    {
        if (GCD % i == 0)
        {
            cnt++;
            if (i != (GCD / i))
            {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}