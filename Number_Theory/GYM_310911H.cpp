
// How many numbers are divisible by n and m in the range
// [l,r] (inclusive)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll gcd = __gcd(n, m);
    if ((double)n / gcd > (double)r / m)
    {
        cout << 0 << '\n';
        return 0;
    }

    ll lcm = (n * m) / gcd;
    cout << (r / lcm) - ((l - 1) / lcm) << '\n';
}