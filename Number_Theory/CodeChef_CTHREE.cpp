
// Given an integer N and a triple of integers (a, b, c), compute
// the number of triples of positive integers (x, y, z) such that
// N = x · y · z, x ≤ a, y ≤ b and z ≤ c
// Two triples (x1, y1, z1) and (x2, y2, z2) differ if x1 is not
// equal to x2 or y1 is not equal to y2 or z1 is not equal to z2

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
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        vector<int> v;
        for (int i = 1; i * i <= n; i++)
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

        int ans = 0;
        for (auto x : v)
        {
            if (x <= a)
            {
                for (auto y : v)
                {
                    if (y <= b)
                    {
                        if (n % (1LL * x * y) == 0)
                        {
                            int z = n / (x * y);
                            if (z <= c)
                            {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}