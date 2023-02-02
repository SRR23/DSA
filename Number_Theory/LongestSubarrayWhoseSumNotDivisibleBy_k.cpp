#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, sum = 0, l = -1, r;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (a % x != 0)
            {
                if (l == -1)
                    l = i;
                r = i;
            }
            sum += a;
        }
        if (sum % x)
            cout << n << '\n';
        else if (l == -1)
            cout << -1 << '\n';
        else
            cout << n - min(l + 1, n - r) << '\n';
    }
}